#include "Node.h"
#include <limits>
#include <iostream>

Node::Node(int val) {
    value = val;
    dist = numeric_limits<double>::infinity();
    visited = false;
    parent = nullptr;
}

Node::~Node() {
  // "DONE" FOR YOU
  //
  // This is equivalent to the default destructor the compiler will
  // generate for you. As a rule of thumb, you only need to `delete`
  // member variables that were created with `new` inside this
  // class. So, you don't need to do anything here. It could have been
  // left out of the header/impl file entirely.
}

int Node::getValue() {
    return value;
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

// overloading operator << lets you put a Node object into an output
// stream.
ostream& operator<<(std::ostream& out, Node node) {
  // DONE FOR YOU
  out << node.getValue();
  return out;
}
