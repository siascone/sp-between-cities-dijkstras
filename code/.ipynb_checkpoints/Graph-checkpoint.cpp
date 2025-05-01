#include "Graph.h"

#include <iostream>
#include <sstream>

using namespace std;

Graph::Graph() {}

Graph::~Graph() {}

vector<Node*> Graph::getNodes() {
    return nodes;
}

vector<Edge*> Graph::getEdges() {
    return edges;
}

void Graph::addNode(Node* node) {
    nodes.push_back(node);
}

void Graph::addEdge(Edge* edge) {
    edges.push_back(edge);
}

set<Edge*> Graph::getAdjacentEdges(Node* node) {
    set<Edge*> adjacentEdges;
        
    for (int i = 0; i < static_cast<int>(edges.size()); i++) {
        Edge* edge = edges[i];
        
        if (edge->getNodeA() == node) {
            adjacentEdges.insert(edge);
        }
    }
    
    return adjacentEdges;
}