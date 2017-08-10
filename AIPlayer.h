#ifndef GO_TEST_AIPLAYER_H
#define GO_TEST_AIPLAYER_H

#include "Player.h"
#include "Node.h"
#define SEARCH_ITER 10000
#define RP_SEARCH_ITER 5000

class AIPlayer : public Player{
public:
    AIPlayer(int, Board*&);
    bool createChildren(Node& );
    bool createChildren(Node&, Board& );
    int playSimulation(Node&, Board&, double);
    virtual Node* Select(Node &node, Board&, double);
    void makeMove(int&, int&);
    bool genMove();

    Node* getBestChild(Node& root);
    Node* getRoot();
    void setRoot(Node*);
    void pre_prune(int, int);
    void post_prune(int, int);

protected:
    Node* root;
};

inline Node* AIPlayer::getRoot(){return this->root;}
inline void AIPlayer::setRoot(Node * new_root) {this->root = new_root;}

#endif //GO_TEST_AIPLAYER_H
