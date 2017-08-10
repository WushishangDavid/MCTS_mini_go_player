#ifndef GO_SINGLEGAME_H
#define GO_SINGLEGAME_H

#include "Board.h"
#include "AIPlayer.h"

class SingleGame {
public:
    SingleGame(Board*&, int id, int g_id);
    bool makePlayerMove();
    Board& getBoard();
    AIPlayer* player;

private:
    Board* board;
    int game_id;
};

inline Board& SingleGame::getBoard() {return *(this->board);}

#endif //GO_SINGLEGAME_H
