#include "Edge.h"

Edge::Edge(Node* n1, Node* n2, int w) {
    node_a = n1;
    node_b = n2;
    weight = w;
}

Edge::~Edge() {}

Node* Edge::getNodeA() {
    return node_a;
}

Node* Edge::getNodeB() {
    return node_b;
}

int Edge::getWeight() {
    return weight;
}

void Edge::setWeight(int val) {
    weight = val;
}
