#ifndef GO_TEST_GAME_H
#define GO_TEST_GAME_H


#include "Board.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "LP_AIPlayer.h"
#include "RP_AIPlayer.h"

class Game {
public:
    Game(Board*&, Player*&, Player*&);
    Game(int p1, int p2);
    Board& getBoard();
    void play();
    void changePlayer();
    void makePlayerMove(Player*&, int&, int&);

protected:
    Board* board;
    Player* player1;
    Player* player2;
    Player* curr_player;
};

inline Board& Game::getBoard() {return *(this->board);}

#endif //GO_TEST_GAME_H
