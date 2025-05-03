#ifndef NODE_H__
#define NODE_H__

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Node {
private:
    string name; // city name of node
    double dist; // distance of node
    bool visited;
    Node* parent;   // parent of node in sp.
    int idx_in_pq; // index in priority queue

public:
    Node(string n); // constructor
    ~Node(); // deconstructor
    string getName(); // getter for name of node
    double getDist(); // getter for distance of node
    void setDist(double d); // setter for distance of node
    bool isVisited(); // return true or false if node has been visited
    void setVisited(bool val); // set visited state of node, used in sp calculation
    Node* getParent(); // getter for node parent
    void setParent(Node* node); // setter for node parent
    int getIdxInPQ(); // getter for idx_in_pq
    void setIdxInPQ(int idx); // setter for idx_in_pq
    
};

#endif // NODE_H__
