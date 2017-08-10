#ifndef GO_ENSEMBLE_GAME_H
#define GO_ENSEMBLE_GAME_H

#include "SingleGame.h"
#include "Player.h"
#include <vector>
#include <omp.h>

#ifndef NUM_THREAD
#define NUM_THREAD 2
#endif

class RP_AIPlayer : public Player{
public:
    RP_AIPlayer(int, Board*&);
    void makeMove(int& x, int& y);
    void pre_prune(int x, int y);
    void post_prune(int x, int y);
    void getBestChild(int &x, int& y);

protected:
    SingleGame* games[NUM_THREAD];
};

#endif //GO_ENSEMBLE_GAME_H
