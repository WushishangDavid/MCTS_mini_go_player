#include "Game.h"

// extern int count;

Game::Game(Board*& b, Player*& p1, Player*& p2)
        :player1(p1), player2(p2), curr_player(p1), board(b) {}

Game::Game(int p1, int p2){
    this->board = new Board();

    if(p1==1)
        this->player1 = new HumanPlayer(1, board);
    else if(p1==2)
        this->player1 = new AIPlayer(1, board);
    else
        this->player1 = new LP_AIPlayer(1,board);

    if(p2==1)
        this->player2 = new HumanPlayer(2, board);
    else if(p2==2)
        this->player2 = new AIPlayer(2, board);
    else
        this->player2 = new LP_AIPlayer(2, board);

    this->curr_player = this->player1;
}

void Game::play(){
    using namespace std;

    srand((unsigned)time(NULL));
    int moves = 0;
    int influence_winner;
    int x, y;

    // FIXME: extend the limit of 30 rounds
    while(moves < 30) {
        //cout << "Count of nodes: " << count << endl;
        moves++;

        this->makePlayerMove(this->player1, x, y);
        if(this->board->isLegalPlay(x, y))
            this->board->setMove(x, y);
        else{
            cerr << "Something goes wrong!" <<endl;
        }
        cout << *(this->board) << "------------------" << endl;

        //cout << "Count of nodes: " << count << endl;

        if(this->board->getMovements() > 1){
            this->player2->post_prune(x, y);
        }

        //cout << "Count of nodes: " << count << endl;

        this->makePlayerMove(this->player2, x, y);
        if(this->board->isLegalPlay(x, y))
            this->board->setMove(x, y);
        else{
            cerr << "Something goes wrong!" <<endl;
        }
        cout << *(this->board) << "------------------" << endl;

        //cout << "Count of nodes: " << count << endl;

        if(this->board->getMovements() > 1){
            this->player1->post_prune(x, y);
        }
    }

    influence_winner = this->board->influence();
    cout << "Game finished" << endl;
    if(influence_winner)
        cout << "Winner by default influence function: player " << influence_winner << endl;
    cout << "The winner by counting is player " << this->board->getWinner() << endl;
}

void Game::changePlayer(){
    this->curr_player = (this->curr_player == this->player1 ? this->player2 : this->player1);
};

void Game::makePlayerMove(Player*& player, int& x, int& y){
    player->makeMove(x, y);
    this->changePlayer();
    std::cout << "A move has been made!" << std::endl;
}