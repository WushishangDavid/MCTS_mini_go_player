#include "SingleGame.h"

SingleGame::SingleGame(Board*& b, int id, int g_id) {
    this->board = b;
    this->player = new AIPlayer(id, this->board);
    this->game_id = g_id;
}

bool SingleGame::makePlayerMove() {
    this->player->genMove();
    std::cout << "Subgame " << this->game_id << " has finished!" << std::endl;
}