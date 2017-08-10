#include "Node.h"

/* Node.cpp */

#include <cstdlib>

//extern int count;

Node::Node(int x, int y) {
    this->wins = 0;
    this->visits = 0;
    this->x = x;
    this->y = y;
    this->child = NULL;
    this->sibling = NULL;
    //count++;
}

Node::~Node() {
    if(this->sibling != NULL) delete(this->sibling);
    if(this->child != NULL) delete(this->child);
    //count--;
}

void Node::update(int val) {
    this->visits++;
    this->wins += val;
}

void Node::update_para(int val, int vis) {
    this->visits += vis;
    this->wins += val;
}

double Node::getWinRate() {
    if(this->getVisits() > 0) {
        return (double)(this->getWins() / this->getVisits());
    }
    else {
        return 0; /* Should not happen */
    }
}

int Node::getWins() const {
    return this->wins;
}

int Node::getVisits() const {
    return this->visits;
}

int Node::getX() const {
    return this->x;
}

int Node::getY() const {
    return this->y;
}

Node *Node::getChild() const {
    return this->child;
}

void Node::setChild(Node *child) {
    this->child = child;
}

Node *Node::getSibling() const {
    return this->sibling;
}

void Node::setSibling(Node *sibling) {
    this->sibling = sibling;
}
