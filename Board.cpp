#include "Board.h"

Board::Board() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            this->b[i][j] = 0;
        }
    }
    this->curr_playerID = 1;
    this->movements = 0;
    this->moku1 = 0;
    this->moku2 = 0;
    this->ko = false;
}

void Board::setMove(int x, int y){
    int captures = 0;
    this->ko = false;
    this->b[x][y] = this->curr_playerID;

    int op_id = 3 - this->curr_playerID;

    // Checks and removes if move captures any stone
    // Checks north
    if(x > 0 && b[x-1][y] == op_id && isDead(x-1,y)) {
        captures += removeGroup(x-1,y);
    }
    // Checks east
    if(y < BOARD_SIZE-1 && b[x][y+1] == op_id && isDead(x,y+1)) {
        captures += removeGroup(x,y+1);
    }
    // Checks south
    if(x < BOARD_SIZE-1 && b[x+1][y] == op_id && isDead(x+1,y)) {
        captures += removeGroup(x+1,y);
    }
    // Checks west
    if(y > 0 && b[x][y-1] == op_id && isDead(x,y-1)) {
        captures += removeGroup(x,y-1);
    }
    if(captures == 1) {
        this->ko = true;
        this->koX = x;
        this->koY = y;
    }
    if(op_id == 1) moku2 += captures;
    else moku1 += captures;
    this->movements++;

    this->curr_playerID = op_id;
    // TO DO: Prune the tree of AI Player
}

/* Removes a group of stones from the board */
int Board::removeGroup(int x, int y) {
    int group = b[x][y];

    int north = 0;
    int east = 0;
    int south = 0;
    int west = 0;

    b[x][y] = 0;
    // removes north if from the same group
    if(x > 0 && b[x-1][y] == group) north = removeGroup(x-1,y);
    // removes east if from the same group
    if(y < BOARD_SIZE-1 && b[x][y+1] == group) east = removeGroup(x,y+1);
    // removes south if from the same group
    if(x < BOARD_SIZE-1 && b[x+1][y] == group) south = removeGroup(x+1,y);
    // removes west if from the same group
    if(y > 0 && b[x][y-1] == group) west = removeGroup(x,y-1);

    return 1+north+east+south+west;
}

bool Board::isLegalPlay(int x, int y, int ID){
    bool suicide;
    bool kills = false;

    // Check if there is a stone already
    if(this->b[x][y] != 0) return false;
    // Check if ko
    this->b[x][y] = ID;
    if(this->ko) {
        if((koX == 0 || b[koX-1][koY] == ID)
           && (koY == BOARD_SIZE-1 || b[koX][koY+1] == ID)
           && (koX == BOARD_SIZE-1 || b[koX+1][koY] == ID)
           && (koY == 0 || b[koX][koY-1] == ID)) {
            this->b[x][y] = 0;
            return false;
        }
    }
    // Check if suicide play
    suicide = isDead(x, y);
    // Check if kills any opponent stones
    kills = ((x == 0 || ID != 3-b[x-1][y] ? false : isDead(x-1,y))
             || (y == BOARD_SIZE-1 || ID != 3-b[x][y+1] ? false : isDead(x,y+1))
             || (x == BOARD_SIZE-1 || ID != 3-b[x+1][y] ? false : isDead(x+1,y))
             || (y == 0 || ID != 3-b[x][y-1] ? false : isDead(x,y-1)));

    this->b[x][y] = 0;

    return ((!suicide) || kills);
};

bool Board::isLegalPlay(int x, int y){
    bool suicide;
    bool kills = false;

    // Check if there is a stone already
    if(this->b[x][y] != 0) return false;
    // Check if ko
    this->b[x][y] = this->curr_playerID;
    if(this->ko) {
        if((koX == 0 || b[koX-1][koY] == this->curr_playerID)
           && (koY == BOARD_SIZE-1 || b[koX][koY+1] == this->curr_playerID)
           && (koX == BOARD_SIZE-1 || b[koX+1][koY] == this->curr_playerID)
           && (koY == 0 || b[koX][koY-1] == this->curr_playerID)) {
            this->b[x][y] = 0;
            return false;
        }
    }
    // Check if suicide play
    suicide = isDead(x, y);
    // Check if kills any opponent stones
    kills = ((x == 0 || this->curr_playerID != 3-b[x-1][y] ? false : isDead(x-1,y))
             || (y == BOARD_SIZE-1 || this->curr_playerID != 3-b[x][y+1] ? false : isDead(x,y+1))
             || (x == BOARD_SIZE-1 || this->curr_playerID != 3-b[x+1][y] ? false : isDead(x+1,y))
             || (y == 0 || this->curr_playerID != 3-b[x][y-1] ? false : isDead(x,y-1)));

    this->b[x][y] = 0;

    return ((!suicide) || kills);
};

bool Board::isDead(int x, int y) {
    // first checks if there is any liberty on the sides
    if((x > 0 && b[x-1][y] == 0) || (y < BOARD_SIZE-1 && b[x][y+1] == 0) ||
       (x < BOARD_SIZE-1 && b[x+1][y] == 0) || (y > 0 && b[x][y-1] == 0)) {
        return false;
    }

    bool north = true;
    bool east = true;
    bool south = true;
    bool west = true;

    int group = b[x][y];
    /* recursively checks other stones of the same group */

    // marks as already visited
    b[x][y] *= -1;

    // checks north
    if(x > 0 && group == b[x-1][y]) {
        north = isDead(x-1, y);

    }
    // checks east
    if(y < BOARD_SIZE-1 && group == b[x][y+1]) {
        east = isDead(x, y+1);
    }
    // checks south
    if(x < BOARD_SIZE-1 && group == b[x+1][y]) {
        south = isDead(x+1, y);
    }
    // checks west
    if(y > 0 && group == b[x][y-1]) {
        west = isDead(x, y-1);
    }

    // returns board to original state
    b[x][y] *= -1;

    return (north && west && south && east);
}

/* Copies the board state (player omitted) */
void Board::copyStateFrom(const Board* orig) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            this->b[i][j] = orig->b[i][j];
        }
    }
    this->moku1 = orig->moku1;
    this->moku2 = orig->moku2;
    this->movements = orig->movements;
    this->ko = orig->ko;
    this->koX = orig->koX;
    this->koY = orig->koY;
    this->curr_playerID = orig->curr_playerID;
}

/* Calculates board influence using Zobrist algorithm */
int Board::influence() {
    Board clone;
    Board temp;
    int winner = 0;

    clone.copyStateFrom(this);
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(clone.b[i][j] != 0) clone.b[i][j] = clone.b[i][j] == 1 ? 50 : -50;
        }
    }
    temp.copyStateFrom(&clone);
    for(int t = 0; t < 4; t++) {
        for(int i = 0; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                int north = i == 0 ? 0 : clone.b[i-1][j];
                int east = j == BOARD_SIZE-1 ? 0 : clone.b[i][j+1];
                int south = i == BOARD_SIZE-1 ? 0 : clone.b[i+1][j];
                int west = j == 0 ? 0 : clone.b[i][j-1];
                temp.b[i][j] += north + east + south + west;
            }
        }
        clone.copyStateFrom(&temp);
    }

    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(clone.b[i][j] > 500) winner++;
            else if(clone.b[i][j] < -500) winner--;
        }
    }
    winner += (int)this->moku1%1;
    winner -= (int)this->moku2%1;

    return winner == 0 ? 0 : (winner > 0 ? 1 : 2);
}

/* Checks the endgame board state and returns the winner of the game */
int Board::getWinner() {
    Board clone;
    int p1pts = 0, p2pts = 0;
    int value;

    clone.copyStateFrom(this);

    /* Extends players territories with their stones */
    for(int k = 0; k < TERR_ITER_NUMBER; k++) {
        for(int i = 0; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                if(clone.b[i][j] == 0) {
                    clone.b[i][j] = clone.own(i, j);
                }
            }
        }
    }

    /* Counts each player's stones */
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            value = clone.own(i, j);
            switch(value) {
                case 1:
                    p1pts++;
                    break;
                case 2:
                    p2pts++;
                    break;
            }
        }
    }

    /* Player 1 wins */
    if(p1pts > p2pts) {
        return 1;
    }

        /* Player 2 wins */
    else if(p1pts < p2pts) {
        return 2;
    }

        /* Draw */
    else {
        return 0;
    }
}

/* Verifies and returns which player owns (approximately) a board position */
int Board::own(int x, int y) {
    /* Trivial case: there is a player's stone */
    if(this->b[x][y] == 1) {
        return 1;
    }
    else if(this->b[x][y] == 2) {
        return 2;
    }

        /* Case where there is no stone: verify adjacent positions */
    else {
        int p1stones = 0, p2stones = 0;
        int value;
        if(x > 0) {
            value = this->b[x-1][y];
            this->updateStones(value, p1stones, p2stones);
        }
        if(y < BOARD_SIZE-1) {
            value = this->b[x][y+1];
            this->updateStones(value, p1stones, p2stones);
        }
        if(x < BOARD_SIZE-1) {
            value = this->b[x+1][y];
            this->updateStones(value, p1stones, p2stones);
        }
        if(y > 0) {
            value = this->b[x][y-1];
            this->updateStones(value, p1stones, p2stones);
        }

        if(p1stones > p2stones) {
            return 1;
        }
        else if(p1stones < p2stones) {
            return 2;
        }
        else {
            return 0;
        }
    }
}

/* Plays random moves until endgame and returns the winner */
int Board::playRandomGame() {
    int curr = this->curr_playerID;

    while(!isFinished()) {
        this->makeRandomMove();
    }

    return getWinner() == curr ? 1 : 0;
}

int Board::playRandomGameI() {
    int curr = this->curr_playerID;

    while(!isFinished()) {
        this->makeRandomMove();
    }

    return influence() == curr ? 1 : 0;
}

/* Checks the board state and returns if the game is finished */
bool Board::isFinished() {
    if(this->movements > 65) return true;
    return false;
}

/* Random chooses a position on the board to play. Tries until a legal move
 * is found */
void Board::makeRandomMove() {

    int x = rand()%BOARD_SIZE;
    int y = rand()%BOARD_SIZE;
    while(!isLegalPlay(x, y, this->curr_playerID)) {
        x = rand()%BOARD_SIZE;
        y = rand()%BOARD_SIZE;
    }

    this->setMove(x, y);
}

/* Updates the number of stones around a board position */
void Board::updateStones(int value, int& p1stones, int& p2stones) {
    switch(value) {
        case 1:
            p1stones++;
            break;
        case 2:
            p2stones++;
            break;
    }
}

std::ostream & operator<<(std::ostream & os, const Board &board) {
    using namespace std;

    os << "  ";
    for(int i = 0; i < BOARD_SIZE; i++) os << i << " ";
    os << endl;
    for(int i = 0; i < BOARD_SIZE; i++) {
        os << i << " ";
        for(int j = 0; j < BOARD_SIZE; j++) {
            switch(board.b[i][j]) {
                case 0:
                    os << ". ";
                    break;
                case 1:
                    os << "X ";
                    break;
                case 2:
                    os << "O ";
                    break;
            }
        }
        os << endl;
    }
    os << "Captures1: " << board.moku1 << endl;
    os << "Captures2: " << board.moku2 << endl;
    return os;
}