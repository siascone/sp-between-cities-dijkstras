#ifndef GRAPH_H__
#define GRAPH_H__

#include "Edge.h"
#include "Node.h"
#include <memory>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Graph {
    
private:
    vector<Node*> nodes; // vector of nodes (cities)
    vector<Edge*> edges; // vector of edges (roads)

    vector<Edge*> search_edges; // used in sp discovery
    vector<Node*> search_nodes; // used in sp discovery
    
public:
    Graph(); // Constructor
    ~Graph(); // Deconstructor
    vector<Node*> getNodes(); // returns vector of nodes (cities)
    vector<Edge*> getEdges(); // returns vector of edges (roads between cities)
    void addNode(Node* n); // add a node to the graph
    void addEdge(Edge* e); // add an edge to the graph
    
    // return set of edges from a city to other cities
    set<Edge*> getAdjacentEdges(Node* node); 

};

#endif // GRAPH_H__