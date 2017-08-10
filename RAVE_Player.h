#ifndef GO_TEST_RAVE_PLAYER_H
#define GO_TEST_RAVE_PLAYER_H

#include "AIPlayer.h"
#include "Rave_Node.h"

class RAVE_Player : public AIPlayer {
public:
    RAVE_Player(int, Board*&);
    Node* Select(Node& node, Board& board);

private:

};


#endif //GO_TEST_RAVE_PLAYER_H
