#include "LP_AIPlayer.h"
#include <cmath>

LP_AIPlayer::LP_AIPlayer(int id, Board*& b)
        : Player(id, b) {
    this->root = new Node(-1,-1);
}

bool LP_AIPlayer::createChildren(Node& root) {
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
bool LP_AIPlayer::createChildren(Node& root, Board& board) {
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

int LP_AIPlayer::playSimulation(Node& node, Board& board) {
    int randomresult = 0;
    if(node.getChild() == NULL && node.getVisits() < 1) {
        randomresult = this->playRandomGame(board);
    }
    else {
        if(node.getChild() == NULL) createChildren(node, board);

        Node* next = Select(node, board);
        board.setMove(next->getX(), next->getY());

        int res = playSimulation(*next, board);
        randomresult = NUM_THREAD-res;
    }

    node.update_para(NUM_THREAD-randomresult, NUM_THREAD);
    return randomresult;
}

int LP_AIPlayer::playRandomGame(Board& board){
    int i;
    int res = 0;

    #pragma omp parallel for reduction(+:res)
    for(i=0; i<NUM_THREAD; i++){
        Board temp;
        temp.copyStateFrom(&board);
        res+=temp.playRandomGame();
    }

    return res;
}

/* Select the best child from a Node based on UCT value */
Node* LP_AIPlayer::Select(Node &node, Board &board) {
    Node* res = NULL;
    Node* next = node.getChild();
    double best_uct = 0;

    while(next != NULL) {
        double uctvalue;
        if(next->getVisits() > 0) {
            double winrate = next->getWinRate();
            double uct = 0.44 * sqrt(log(node.getVisits()) / next->getVisits());
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

void LP_AIPlayer::makeMove(int& x, int& y){
    if(this->root->getChild() == NULL)
        createChildren(*this->root);

    Board clone;

    // Skip first
    for(int i = 0; i < LP_SEARCH_ITER; i++) {
        clone.copyStateFrom(this->board);
        this->playSimulation(*this->root, clone);
    }

    Node* n = getBestChild(*this->root);
    // Self-prune: head & tail
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
Node* LP_AIPlayer::getBestChild(Node& root) {
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

void LP_AIPlayer::post_prune(int x, int y) {
    if(this->getRoot()->getChild() != NULL) {
        std::cout << "Prune for the MCTree of player" << this->getID() << " !" << std::endl;
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