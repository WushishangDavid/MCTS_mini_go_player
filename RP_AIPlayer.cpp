#include "RP_AIPlayer.h"

RP_AIPlayer::RP_AIPlayer(int id, Board*& b)
        : Player(id, b){
    for(int i=0; i<NUM_THREAD; i++)
        this->games[i] = new SingleGame(b, id, i);
}

void RP_AIPlayer::makeMove(int& x, int& y) {
    #pragma omp parallel for
    for(int i=0; i<NUM_THREAD; i++)
        this->games[i]->makePlayerMove();
    this->getBestChild(x, y);
    // Self-prune the MC Trees
    this->pre_prune(x, y);
}

/* Select the child from a Node with the most number of simulations */
void RP_AIPlayer::getBestChild(int &x, int &y) {

    // Initialize the ensemble array
    int visits[BOARD_SIZE][BOARD_SIZE];
    int wins[BOARD_SIZE][BOARD_SIZE];

    for(int i=0; i<BOARD_SIZE; i++)
        for(int j=0; j<BOARD_SIZE; j++){
            visits[i][j] = 0;
            wins[i][j] = 0;
    }

    // Assemble the information from all MC Trees
    for(int i=0; i<NUM_THREAD; i++){
        Node* child = this->games[i]->player->getRoot()->getChild();
        while(child != NULL) {
            visits[child->getX()][child->getY()] = child->getVisits();
            wins[child->getX()][child->getY()] = child->getWins();
            child = child->getSibling();
        }
    }

    // Select the most visited child.
    int best_visits = -1;
    int best_wins = -1;
    int best_x = -1;
    int best_y = -1;
    for(int i=0; i<BOARD_SIZE; i++)
        for(int j=0; j<BOARD_SIZE; j++){
            if(visits[i][j] >= best_visits && wins[i][j] > best_wins) {
                best_x = i;
                best_y = j;
                best_visits = visits[i][j];
                best_wins = wins[i][j];
            }
            else if(visits[i][j] == best_visits &&
                    wins[i][j] == best_wins && rand()%2 == 0) {
                best_x = i;
                best_y = j;
                best_visits = visits[i][j];
                best_wins = wins[i][j];
            }
        }

    x = best_x;
    y = best_y;
}

void RP_AIPlayer::pre_prune(int x, int y) {
    //#pragma omp parallel for
    for(int i=0; i<NUM_THREAD; i++)
        this->games[i]->player->pre_prune(x, y);
}

void RP_AIPlayer::post_prune(int x, int y) {
    //#pragma omp parallel for
    for(int i=0; i<NUM_THREAD; i++)
        this->games[i]->player->post_prune(x, y);
}