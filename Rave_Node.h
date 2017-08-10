#ifndef GO_TEST_RAVE_NODE_H
#define GO_TEST_RAVE_NODE_H

#include "Node.h"
#define BOARD_SIZE 9

class Rave_Node : public Node {
public:
    Rave_Node(int x, int y);
    void update(int val);

private:
    int RAVE_value[BOARD_SIZE][BOARD_SIZE] = 0;
};


#endif //GO_TEST_RAVE_NODE_H
