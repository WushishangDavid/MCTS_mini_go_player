#include <iostream>
#include "Game.h"

using namespace std;

//int count=0;

void mcts(){
    int player1, player2;
    Player *p1, *p2;
    Board* board = new Board;

    cout << "Please select the type of first player: " <<endl;
    cout << "1.Human\n2.AI\n3.LP_AI\n4.RP_AI" << endl;
    cin >> player1;
    cout << "Please select the type of second player: " <<endl;
    cout << "1.Human\n2.AI\n3.LP_AI\n4.RP_AI" << endl;
    cin >> player2;

    switch(player1){
        case 1:
            p1 = new HumanPlayer(1, board);
            break;
        case 2:
            p1 = new AIPlayer(1, board);
            break;
        case 3:
            p1 = new LP_AIPlayer(1, board);
            break;
        case 4:
            p1 = new RP_AIPlayer(1, board);
            break;
        default:
            cerr << "Invalid input!" << endl;
            exit(0);
    }

    switch(player2){
        case 1:
            p2 = new HumanPlayer(2, board);
            break;
        case 2:
            p2 = new AIPlayer(2, board);
            break;
        case 3:
            p2 = new LP_AIPlayer(2, board);
            break;
        case 4:
            p2 = new RP_AIPlayer(2, board);
            break;
        default:
            cerr << "Invalid input!" << endl;
            exit(0);
    }

    Game game(board,p1,p2);

    game.play();

    cout << game.getBoard() << "------------------" << endl;
}

int main() {
    omp_set_num_threads(NUM_THREAD);

    /* Initialize the game */
    cout << "Game Starts!" << endl;
    mcts();

    return 0;
}