#include "Graph.h"

#include <iostream>
#include <sstream>

using namespace std;

Graph::Graph() {}

Graph::~Graph() {}

vector<Node*> Graph::getNodes() {
    return nodes;
}

Node* Graph::findNode(string name) {
    Node* node = nullptr;
    
    for (int i = 0; static_cast<int>(nodes.size()); i++) {
        if (nodes[i]->getName() == name) {
            node = nodes[i];
            break;
        }
    }
    
    return node;
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

vector<Node*> Graph::computeShortestPath(Node* start, Node* end){
    // set start node dist, all nodes initiated to infinity
    start->setDist(0);
    
    Pqueue* pq = new Pqueue();
    pq->insert(start);
    
    while (!pq->isEmpty()) {
        // retreive and process nearest node
        Node* curr_node = pq->getAndDeleteMin();
        curr_node->setVisited(true);
                
        // find neighbor edges of curr_node
        set<Edge*> neighbor_edges = this->getAdjacentEdges(curr_node);
        
        // explore neighbor edges of current node and update accordingly
        for (Edge* edge : neighbor_edges) {
            Node* neighbor_node = edge->getNodeB();
            double weight = edge->getWeight();
            
            // if neighbor unvisited and distance can be relaxed update and add node to queue
            if (!neighbor_node->isVisited() && curr_node->getDist() + weight < neighbor_node->getDist()) {
                neighbor_node->setDist(curr_node->getDist() + weight);
                neighbor_node->setParent(curr_node);
                if (neighbor_node->getIdxInPQ() == -1) { // neighbor is not in queue
                    pq->insert(neighbor_node);
                } else { // neighbor in queue and was relaxed, bubble up
                    pq->updateNodeWeight(neighbor_node);
                }
            }
        }
    }
    
    // build path from end node
    vector<Node*> sp = this->buildPath(end);
    
    return sp;
}

vector<Node*> Graph::buildPath(Node* node) {
    vector<Node*> sp;
    sp.insert(sp.begin(), node);
    
    Node* curr_node = node;
        
    while (curr_node->getParent() != nullptr) {
        // add parent to path and update curr_node to parent
        sp.insert(sp.begin(), curr_node->getParent());
        curr_node = curr_node->getParent();
    }
    
    return sp;
}
