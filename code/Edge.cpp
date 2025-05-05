#include "Edge.h"

Edge::Edge(Node* n1, Node* n2, double w) {
    node_a = n1;
    node_b = n2;
    weight = w;
}

Edge::~Edge() {}

Node* Edge::getNodeA() { // return node_a
    return node_a;
}

Node* Edge::getNodeB() { // return node_b
    return node_b;
}

double Edge::getWeight() { // return edge weight
    return weight;
}

void Edge::setWeight(int val) { // set edge weight
    weight = val;
}
