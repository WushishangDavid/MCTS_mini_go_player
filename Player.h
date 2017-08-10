#ifndef GO_TEST_PLAYER_H
#define GO_TEST_PLAYER_H

#include <cstdlib>
#include <iostream>
#include "Board.h"

class Player{
public:
    Player(int, Board*&);
    virtual void makeMove(int&, int&) = 0;
    virtual void post_prune(int, int);
    int getID();

protected:
    Board* board;
    int ID;
};

inline int Player::getID() {return this->ID;}
inline void Player::post_prune(int x, int y) {}


#endif //GO_TEST_PLAYER_H
