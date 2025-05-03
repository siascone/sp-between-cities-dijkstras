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
    
    cout << "------- NEIGHBOR EDGES -------" << endl;
    for (Edge* edge : adjacentEdges) {
        cout << "A: " << edge->getNodeA()->getName() << " B: " << edge->getNodeB()->getName() << endl;
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
        
        cout << endl << curr_node->getName() << endl << endl;
        
        // find neighbor edges of curr_node
        set<Edge*> neighbor_edges = this->getAdjacentEdges(curr_node);
        
        for (Edge* edge : neighbor_edges) {
            Node* neighbor_node = edge->getNodeB();
            double weight = edge->getWeight();
            
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
    
    // for (int i = 0; i < static_cast<int>(sp.size()); i++) {
    //     cout << "name: "<< sp[i]->getName() << " dist: " << sp[i]->getDist() << endl;
    // }
    
    return sp;
}

vector<Node*> Graph::buildPath(Node* node) {
    vector<Node*> sp;
    sp.insert(sp.begin(), node);
    Node* curr_node = node;
    
    // cout << "building path..." << endl;
    
    while (curr_node->getParent() != nullptr) {
        // cout << endl << curr_node->getParent()->getName() << endl;
        sp.insert(sp.begin(), curr_node->getParent());
        
        curr_node = curr_node->getParent();
    }
    
    return sp;
}


// def buildPath(vertex):
//     path = []
//     curr_vrtx = vertex
    
//     # as long as there is a parent of the current vertex add it to the front of path
//     while curr_vrtx.pi is not None:
//         # get parent x and y
//         pi_x = curr_vrtx.pi.x
//         pi_y = curr_vrtx.pi.y
//         # add to front of path, building backwards
//         path.insert(0, (pi_x, pi_y))
        
//         # update current vertex to parent
//         curr_vrtx = curr_vrtx.pi
        
//     return path

