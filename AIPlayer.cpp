#include "AIPlayer.h"
#include <cmath>

AIPlayer::AIPlayer(int id, Board*& b)
        : Player(id, b) {
    this->root = new Node(-1,-1);
}

bool AIPlayer::createChildren(Node& root) {
    Node* last = NULL;
    bool ret = false;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(this->board->isLegalPlay(i, j, this->ID)) {
                ret = true;
                if(last == NULL) {
                    root.setChild(new Node(i,j));
                    last = root.getChild();
                }
                else {
                    last->setSibling(new Node(i,j));
                    last = last->getSibling();
                }
            }
        }
    }

    return ret;
}

// Version for simulation
bool AIPlayer::createChildren(Node& root, Board& board) {
    Node* last = NULL;
    bool ret = false;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board.isLegalPlay(i, j)) {
                ret = true;
                if(last == NULL) {
                    root.setChild(new Node(i,j));
                    last = root.getChild();
                }
                else {
                    last->setSibling(new Node(i,j));
                    last = last->getSibling();
                }
            }
        }
    }

    return ret;
}

/* Plays a game simulation and returns who was the winner saving the wins and
 * games on the tree nodes
 * FIXME: Can be implemented using a while loop*/
int AIPlayer::playSimulation(Node& node, Board& board, double rate = 0.44) {
    int randomresult = 0;
    if(node.getChild() == NULL && node.getVisits() < 1) {
        randomresult = board.playRandomGame();
    }
    else {
        if(node.getChild() == NULL) createChildren(node, board);

        Node* next = Select(node, board, rate);
        board.setMove(next->getX(), next->getY());

        randomresult = 1 - playSimulation(*next, board);

    }

    // CAUTIONS: 1 - randomresult due to implementation details!
    node.update(1 - randomresult);
    return randomresult;
}

/* Select the best child from a Node based on UCT value */
Node* AIPlayer::Select(Node &node, Board &board , double rate) {
    Node* res = NULL;
    Node* next = node.getChild();
    double best_uct = 0;

    while(next != NULL) {
        double uctvalue;
        if(next->getVisits() > 0) {
            double winrate = next->getWinRate();
            double uct = rate * sqrt(log(node.getVisits()) / next->getVisits());
            uctvalue = winrate + uct;
        }
        else {
            uctvalue = 10000 + 1000*(rand()%1000);
        }

        if(uctvalue > best_uct) {
            best_uct = uctvalue;
            res = next;
        } else if(uctvalue == best_uct && rand()%2 == 0) {
            best_uct = uctvalue;
            res = next;
        }

        next = next->getSibling();
    }

    return res;
}

void AIPlayer::makeMove(int& x, int& y){
    if(this->root->getChild() == NULL)
        createChildren(*this->root);

    Board clone;

    // Skip first
    for(int i = 0; i < SEARCH_ITER ; i++) {
        clone.copyStateFrom(this->board);
        this->playSimulation(*this->root, clone);
    }

    // Self-prone 1st
    Node* n = getBestChild(*this->root);
    // Self-prune 2nd: head & tail
    Node* todelete = this->root;
    this->root = n;
    delete(todelete);
    delete(this->root->getSibling());
    this->root->setSibling(NULL);
    // Set the generated move on board
    x = n->getX();
    y = n->getY();
    std::cout << "(" << x << "," << y << ")" << std::endl;
    //this->board->setMove(x, y);
}

/* Select the child from a Node with the most number of simulations */
Node* AIPlayer::getBestChild(Node& root) {
    Node* child = root.getChild();
    Node* best_child = NULL;
    int best_visits = -1;
    int best_wins = -1;
    while(child != NULL) {
        if(child->getVisits() >= best_visits && child->getWins() > best_wins) {
            best_child = child;
            best_visits = child->getVisits();
            best_wins = child->getWins();
        } else if(child->getVisits() == best_visits &&
                  child->getWins() == best_wins && rand()%2 == 0) {
            best_child = child;
            best_visits = child->getVisits();
            best_wins = child->getWins();
        }
        child = child->getSibling();
    }

    // Unattach previous best sibling for memory free: self-prune
    child = root.getChild();
    if(child == best_child) root.setChild(NULL);
    else {
        while(child->getSibling() != best_child) child = child->getSibling();
        child->setSibling(NULL);
    }
    return best_child;
}

void AIPlayer::pre_prune(int x, int y) {
    if(this->getRoot()->getChild() != NULL) {
        std::cout << "Pre-prune for the MCTree of player" << this->getID() << " !" << std::endl;
        Node *curr_root = this->getRoot();
        Node *move = curr_root->getChild();

        if (move->getX() == x && move->getY() == y) {
            curr_root->setChild(NULL);
            Node *todelete = curr_root;
            curr_root = move;
            delete (todelete);
            delete (curr_root->getSibling());
            curr_root->setSibling(NULL);
            this->setRoot(curr_root);
        } else {
            Node *sibling = move->getSibling();
            while (sibling->getX() != x || sibling->getY() != y) {
                move = move->getSibling();
                sibling = sibling->getSibling();
            }
            move->setSibling(NULL);
            Node *todelete = curr_root;
            curr_root = sibling;
            delete (todelete);
            delete (curr_root->getSibling());
            curr_root->setSibling(NULL);
            this->setRoot(curr_root);
        }
    }
}

void AIPlayer::post_prune(int x, int y) {
    if(this->getRoot()->getChild() != NULL) {
        std::cout << "Post-prune for the MCTree of player" << this->getID() << " !" << std::endl;
        Node *curr_root = this->getRoot();
        Node *move = curr_root->getChild();

        if (move->getX() == x && move->getY() == y) {
            curr_root->setChild(NULL);
            Node *todelete = curr_root;
            curr_root = move;
            delete (todelete);
            delete (curr_root->getSibling());
            curr_root->setSibling(NULL);
            this->setRoot(curr_root);
        } else {
            Node *sibling = move->getSibling();
            while (sibling->getX() != x || sibling->getY() != y) {
                move = move->getSibling();
                sibling = sibling->getSibling();
            }
            move->setSibling(NULL);
            Node *todelete = curr_root;
            curr_root = sibling;
            delete (todelete);
            delete (curr_root->getSibling());
            curr_root->setSibling(NULL);
            this->setRoot(curr_root);
        }
    }
}

bool AIPlayer::genMove(){
    if(this->root->getChild() == NULL)
        createChildren(*this->root);

    Board clone;

    for(int i = 0; i < RP_SEARCH_ITER ; i++) {
        clone.copyStateFrom(this->board);
        this->playSimulation(*this->root, clone, 0.05);
    }

    return true;
}