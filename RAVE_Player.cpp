#include "RAVE_Player.h"

RAVE_Player::RAVE_Player(int id, Board *& b)
        : AIPlayer(id, b){
    this->root = new Rave_Node(-1, -1);
}

/* Select the best child from a Node based on a weighted value of UCB and RAVE */
Node* RAVE_Player::Select(Node &node, Board &board) {
    Node* res = NULL;
    Node* next = node.getChild();
    double best_uct = 0;
    double w_uct = 0.1, w_rave = 0.9;

    while(next != NULL) {
        double uctvalue;
        if(next->getVisits() > 0) {
            double winrate = next->getWinRate();
            double uct = 0.44 * sqrt(log(node.getVisits()) / next->getVisits());
            uctvalue = winrate + uct;
        }
        else {
            uctvalue = 10000 + 1000*(rand()%1000);
        }

        if(uctvalue > best_uct) {
            best_uct = uctvalue;
            res = next;
        } else if(uctvalue == best_uct && rand()%2 == 0) {
            best_uct = uctvalue;
            res = next;
        }

        next = next->getSibling();
    }

    return res;
}