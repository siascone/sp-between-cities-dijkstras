#include "Node.h"
#include <limits>
#include <iostream>
#include <string>

Node::Node(string n) {
    name = n;
    dist = numeric_limits<double>::infinity();
    visited = false;
    parent = nullptr;
    idx_in_pq = -1;
}

Node::~Node() {}

string Node::getName() { // return node name
    return name;
}

double Node::getDist() { // return node distance
    return dist;
}

void Node::setDist(double d) { // set node distance
    dist = d;
}

bool Node::isVisited() { // return true or false if node has been visited
    return visited;
}

void Node::setVisited(bool val) { // set visited state of node, used in sp calculation
    visited = val;
}

Node* Node::getParent() { // return parent node
    return parent;
}

void Node::setParent(Node* node) { // set parent node
    parent = node;
}

int Node::getIdxInPQ() { // return index in priority queue
    return idx_in_pq;
}

void Node::setIdxInPQ(int idx) { // set index in priority queue
    idx_in_pq = idx;
}
