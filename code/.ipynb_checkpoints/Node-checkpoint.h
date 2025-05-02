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
    string getName(); // return name of node
    double getDist(); // return distance of node
    void setDist(double d);
    bool isVisited(); // return true or false if node has been visited
    void setVisited(bool val);
    Node* getParent(); // getter for node parent
    void setParent(Node* node); // setter for node parent
    int getIdxInPQ();
    void setIdxInPQ(int idx);
    
};

#endif // NODE_H__
