#ifndef EDGE_H__
#define EDGE_H__

#include "Node.h"
// #include <memory>

using namespace std;

class Edge {
private:
    Node* node_a;  // start node
    Node* node_b;  // end node
    double weight; // edge weight
    
public:
    Edge(Node* n1, Node* n2, double w); // constructor
    ~Edge(); // deconstructor
    Node* getNodeA(); // get node a
    Node* getNodeB(); // get node b
    double getWeight();
    void setWeight(int val); // setter for edge weight
};

#endif // EDGE
