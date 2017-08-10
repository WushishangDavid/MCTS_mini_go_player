#ifndef GO_TEST_NODE_H
#define GO_TEST_NODE_H


class Node {
public:
    Node(int x, int y);
    virtual ~Node();
    virtual void update(int val);
    void update_para(int val, int visits);
    double getWinRate();
    int getWins() const;
    int getVisits() const;
    int getX() const;
    int getY() const;
    Node *getChild() const;
    void setChild(Node *);
    Node *getSibling() const;
    void setSibling(Node *);

protected:
    int wins;
    int visits;

    int x, y; /* Position of move */

    Node *child;
    Node *sibling;
};


#endif //GO_TEST_NODE_H
