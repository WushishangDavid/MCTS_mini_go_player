#ifndef GO_TEST_HUMANPLAYER_H
#define GO_TEST_HUMANPLAYER_H

#include "Player.h"

class HumanPlayer: public Player {
public:
    HumanPlayer(int, Board*&);
    // FIXME: User can pass a move
    void makeMove(int&, int&);
};

#endif //GO_TEST_HUMANPLAYER_H
