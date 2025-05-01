#include "Node.h"

Node::Node(string s) {
  // DONE FOR YOU
  data = s;
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

string Node::getData() {
  // DONE FOR YOU
  return data;
}

void Node::setRank(int r) {
  // DONE FOR YOU
  rank = r;
}

void Node::clear() {
  // TODO
    this->color = 1;
    this->discovery_time = -1;
    this->completion_time = -1;
    this->setRank(-1);
    this->setPredecessor(NULL);
}

void Node::setColor(int search_color, int time) {
  // TODO
    this->color = search_color;
    
    if (search_color == 1) {
        this->clear();
    } else if (search_color == 2) {
        this->discovery_time = time;
    } else if (search_color == 3) {
        this->completion_time = time;
    }

}

void Node::getDiscoveryInformation(int& thecolor, int& disco_time,
                                   int& finish_time, int& bfs_rank) {
  // TODO
    thecolor = this->color;
    disco_time = this->discovery_time;
    finish_time = this->completion_time;
    bfs_rank = this->rank;
}

bool Node::isAncestor(Node* other) {
  // TODO
    
    Node* curr_node = this;
    
    while (curr_node != NULL) {
        if (curr_node->predecessor != NULL) {
            if (curr_node->predecessor == other) {
                return true;
            }
        }
        curr_node = curr_node->predecessor;
    }
    
    return false;
}

void Node::setPredecessor(Node* other) {
  // TODO
    this->predecessor = other;
}

// overloading operator << lets you put a Node object into an output
// stream.
ostream& operator<<(std::ostream& out, Node node) {
  // DONE FOR YOU
  out << node.data;
  return out;
}
