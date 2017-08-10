#ifndef GO_TEST_BOARD_H
#define GO_TEST_BOARD_H

#include <cstdlib>
#include <iostream>
#include <time.h>
#define BOARD_SIZE 9
#define TERR_ITER_NUMBER 2

class Board {
public:
    Board();
    void setMove(int, int);
    int removeGroup(int x, int y);
    bool isLegalPlay(int x, int y, int ID);
    bool isLegalPlay(int x, int y);
    bool isDead(int x, int y);
    void copyStateFrom(const Board*);
    int influence();
    int getWinner();
    int getMovements();
    int getCurrPlayerID();
    int own(int x, int y);
    void updateStones(int, int&, int&);
    int playRandomGame();
    int playRandomGameI();
    bool isFinished();
    void makeRandomMove();
    friend std::ostream & operator<<(std::ostream & os, const Board &board);

private:
    int b[BOARD_SIZE][BOARD_SIZE];
    int movements;
    int curr_playerID; // depends
    bool ko;
    int koX, koY;
    double moku1, moku2;
};

inline int Board::getMovements(){return this->movements;};
inline int Board::getCurrPlayerID(){return this->curr_playerID;}

#endif //GO_TEST_BOARD_H
