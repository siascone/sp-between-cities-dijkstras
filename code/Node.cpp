#include "Node.h"
#include <limits>
#include <iostream>
#include <string>

Node::Node(string n) {
    name = n;
    dist = numeric_limits<double>::infinity();
    visited = false;
    parent = nullptr;
}

Node::~Node() {}

string Node::getName() {
    return name;
}

double Node::getDist() {
    return dist;
}

void Node::setDist(double d) {
    dist = d;
}

bool Node::isVisited() {
    return visited;
}

void Node::setVisited(bool val) {
    visited = val;
}

Node* Node::getParent() {
    return parent;
}

void Node::setParent(Node* node) {    
    parent = node;
}
