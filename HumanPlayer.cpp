#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(int id, Board*& b)
        : Player(id, b){}

void HumanPlayer::makeMove(int& x, int& y) {
    using namespace std;

    cout << "Please enter the coordinate: " << endl;
    cin >> x;
    cin >> y;

    while (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE
           || !this->board->isLegalPlay(x, y, this->ID)) {
        cout << "Invalid move! Please enter a coordinate again: " << endl;
        cin >> x;
        cin >> y;
    }

    this->board->setMove(x, y);
}