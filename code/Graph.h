#ifndef GRAPH_H__
#define GRAPH_H__

#include "Edge.h"
#include "Node.h"
#include "Pqueue.h"
#include <set>
#include <string>
#include <vector>

using namespace std;

class Graph {
    
private:
    vector<Node*> nodes; // vector of nodes (cities)
    vector<Edge*> edges; // vector of edges (roads)
    
public:
    Graph(); // Constructor
    ~Graph(); // Deconstructor
    vector<Node*> getNodes(); // returns vector of nodes (cities)
    vector<Edge*> getEdges(); // returns vector of edges (roads between cities)
    void addNode(Node* n); // add a node to the graph
    void addEdge(Edge* e); // add an edge to the graph
    
    // return set of edges from a city to other cities
    set<Edge*> getAdjacentEdges(Node* node); 
    
    // sp with dijkstra's algorithm using pqueue
    vector<Node*> computeShortestPath(Node* start, Node* end);
    
    // build path from node through parent chain
    vector<Node*> buildPath(Node* node);
    

};

#endif // GRAPH_H__