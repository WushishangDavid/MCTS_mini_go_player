#ifndef GO_TEST_LP_AIPLAYER_H
#define GO_TEST_LP_AIPLAYER_H


#include "Player.h"
#include "Node.h"
#include <omp.h>
#define LP_SEARCH_ITER 5000
#ifndef NUM_THREAD
#define NUM_THREAD  2
#endif

class LP_AIPlayer : public Player{
public:
    LP_AIPlayer(int, Board*&);
    bool createChildren(Node& );
    bool createChildren(Node&, Board& );
    int playSimulation(Node&, Board&);
    int playRandomGame(Board& board);
    virtual Node* Select(Node &node, Board&);
    void makeMove(int&, int&);

    Node* getBestChild(Node& root);
    Node* getRoot();
    void setRoot(Node*);
    void post_prune(int, int);

protected:
    Node* root;
};

inline Node* LP_AIPlayer::getRoot(){return this->root;}
inline void LP_AIPlayer::setRoot(Node * new_root) {this->root = new_root;}


#endif //GO_TEST_LP_AIPLAYER_H





