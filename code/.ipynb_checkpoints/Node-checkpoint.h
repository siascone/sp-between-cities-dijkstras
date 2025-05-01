#ifndef NODE_H__
#define NODE_H__

#include <iostream>
#include <memory>

using namespace std;

class Node {
private:
    int value; // id of node
    double dist; // distance of node
    bool visited;
    Node* parent;   // parent of node in sp.

public:
    Node(int val); // constructor
    ~Node(); // deconstructor
    int getValue(); // return id of node
    double getDist(); // return distance of node
    void setDist(double d);
    bool isVisited(); // return true or false if node has been visited
    void setVisited(bool val);
    Node* getParent(); // getter for node parent
    void setParent(Node* node); // setter for node parent
    
};

#endif // NODE_H__
