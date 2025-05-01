#include "Graph.h"

#include <iostream>
#include <sstream>

using namespace std;

// fwd declarations
string make_dot(Graph* g);
string what(int& v);

Graph::Graph() {
  // DONE FOR YOU
  directed = false; // graphs are undirected by default
}

Graph::~Graph() {
  // "DONE" FOR YOU
  // no implementation needed
}

vector<Node*> Graph::getNodes() {
  // DONE FOR YOU
  return nodes;
}

vector<Edge*> Graph::getEdges() {
  // DONE FOR YOU
  return edges;
}

int Graph::getClock() {
  // DONE FOR YOU
  return clock;
}

void Graph::addNode(Node* n) {
  // DONE FOR YOU
  nodes.push_back(n);
}

void Graph::addEdge(Edge* e) {
  // DONE FOR YOU
  edges.push_back(e);
}

void Graph::removeNode(Node* n) {
  // DONE FOR YOU
  for (vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++) {
    if (n == *it) {
      nodes.erase(it);
      break;
    }
  }
}

void Graph::removeEdge(Edge* e) {
  // DONE FOR YOU
  for (vector<Edge*>::iterator it = edges.begin(); it != edges.end(); it++) {
    if (e == *it) {
      edges.erase(it);
      break;
    }
  }
}

void Graph::setDirected(bool val) {
  // DONE FOR YOU
  directed = val;
}

bool Graph::isDirected() {
  // DONE FOR YOU
  return directed;
}

set<Edge*> Graph::getAdjacentEdges(Node* n) {
  // DONE FOR YOU
  set<Edge*> ret;
  for (vector<Edge*>::iterator it = edges.begin(); it != edges.end(); it++) {
    Edge* edge = *it;
    if (edge->getStart() == n) {
      ret.insert(edge);
    }
    if (!directed && (edge->getEnd() == n)) {
      ret.insert(edge);
    }
  }
  return ret;
}

void Graph::clear() {
  // TODO
    vector<Node*> nodes = this->getNodes();
    vector<Edge*> edges = this->getEdges();
    
    for (int i = 0; i < static_cast<int>(nodes.size()); i++) {
        Node* node = nodes[i];
        
        node->clear();
    }
    
    for (int i = 0; i < static_cast<int>(edges.size()); i++) {
        Edge* edge = edges[i];
        
        edge->setType(9);
    }
    
    this->clock = 0;
}

void Graph::tick(string message) {
  // DONE FOR YOU
  //
  // optional debugging function, disabled with if(false) to prevent
  // unused var warning. Change this however you want.
  //
  // recommended use: call it just after incrementing the clock.
  if (false) {
    cout << "// " << message << endl << make_dot(this) << endl;
  }
}

void Graph::dfs(Node* start) {
  // TODO
    clear();
    clock = 0;
    dfsHelper(start);
    
}

void Graph::dfsHelper(Node* node) {
    
    node->setColor(GRAY, clock);
    clock ++;
    search_nodes.push_back(node);
    
    set<Edge*> adjEdges = getAdjacentEdges(node);
    
    for (Edge* edge : adjEdges) {
        Node* neighborNode = nullptr;
        
        if (isDirected()) {
            neighborNode = edge->getEnd();
        } else {
            if (edge->getStart() == node) {
                neighborNode = edge->getEnd();
            } else {
                neighborNode = edge->getStart();
            }
        }
    
        int color;
        int disco_time;
        int finish_time;
        int rank;

        neighborNode->getDiscoveryInformation(color, disco_time, finish_time, rank);

        if (color == WHITE) {
            edge->setType(TREE_EDGE);
            neighborNode->setPredecessor(node);
            search_edges.push_back(edge);
            dfsHelper(neighborNode);
        } else if (color == GRAY) {
            edge->setType(BACK_EDGE);
        } else if (color == BLACK) {
            edge->setType(FORWARD_EDGE);
            // consider adding in update for corss edge using 
            // disvocery and finish times
            // if dt of neighborNode is less than dt of node and ft of node is 
            // less than ft of neighborNode this would be cross edge 
            // (check 3104 algos notes on this)
        }
    }
    
    node->setColor(BLACK, clock);
    clock ++;
}


void Graph::bfs(Node* start) {
  // TODO
    clear();
    clock = 0;
    
    start->setColor(GRAY, clock);
    start->setRank(0);
     
    set<Node*> visited;
    visited.insert(start);
        
    vector<Node*> nodeQueue;
    nodeQueue.push_back(start);
    
    while (!nodeQueue.empty()) {
        Node* currNode = nodeQueue[0];
        nodeQueue.erase(nodeQueue.begin()); // deque
        clock += 1;
        currNode->setColor(BLACK, clock);
        
        int color;
        int disco_time;
        int finish_time;
        int currRank;

        currNode->getDiscoveryInformation(color, disco_time, finish_time, currRank);
            
            
        set<Edge*> adjEdges = getAdjacentEdges(currNode);
            
        for (Edge* edge : adjEdges) {
            Node* descendent = edge->getEnd();
            
            if (!isDirected()) {
                if (descendent == currNode) {
                    descendent = edge->getStart();
                }
            }
            
            if (visited.count(descendent) == 0) {
                clock += 1;
                descendent->setColor(GRAY, clock); // update color
                
                // currRank += 1; // golbaly mutates currRank MISTAKE!
                descendent->setRank(currRank + 1); // set rank
                
                descendent->setPredecessor(currNode); // set parent
                
                nodeQueue.push_back(descendent); // add to queue
                
                search_nodes.push_back(descendent); // add to searched nodes
                search_edges.push_back(edge); // add to searched edges
                visited.insert(descendent); // add to visited
            }
            
        }
        
        search_nodes.push_back(currNode); // add currNode to search nodes after adding children
        // update node rank of all WHITE (undiscovered) nodes to -1
        // LATER: think of an alternative approach as this visits all nodes again
        // this is what clear was for...
//         for (Node* node : getNodes()) {
//             int color;
//             int disco_time;
//             int finish_time;
//             int rank;

//             node->getDiscoveryInformation(color, disco_time, finish_time, rank);
            
//             if (color == WHITE) {
//                 node->setRank(-1);
//             }
//         }
    }
}

void Graph::bfs(Node* start, Node* finish) {
  // TODO
    
    clear();
    clock = 0;
    
    start->setColor(GRAY, clock);
    start->setRank(0);
     
    set<Node*> visited;
    visited.insert(start);
        
    vector<Node*> nodeQueue;
    nodeQueue.push_back(start);
    
    while (!nodeQueue.empty()) {
        Node* currNode = nodeQueue[0];
        nodeQueue.erase(nodeQueue.begin()); // deque
        clock += 1;
        currNode->setColor(BLACK, clock);
        
        int color;
        int disco_time;
        int finish_time;
        int currRank;

        currNode->getDiscoveryInformation(color, disco_time, finish_time, currRank);
        
        // break point if we have found the node we are looking for
        if (currNode == finish) {
            break;
        }
        
            
        set<Edge*> adjEdges = getAdjacentEdges(currNode);
            
        for (Edge* edge : adjEdges) {
            Node* descendent = edge->getEnd();
            
            if (!isDirected()) {
                if (descendent == currNode) {
                    descendent = edge->getStart();
                }
            }
            
            if (visited.count(descendent) == 0) {
                clock += 1;
                descendent->setColor(GRAY, clock); // update color
                
                // currRank += 1; // golbaly mutates currRank MISTAKE!
                descendent->setRank(currRank + 1); // set rank
                
                descendent->setPredecessor(currNode); // set parent
                
                nodeQueue.push_back(descendent); // add to queue
                
                search_nodes.push_back(descendent); // add to searched nodes
                search_edges.push_back(edge); // add to searched edges
                visited.insert(descendent); // add to visited
            }
            
        }
        
        search_nodes.push_back(currNode); // add currNode to search nodes after adding children
        
    }
}

// overloading operator << lets you put a Graph object into an output
// stream.
ostream& operator<<(ostream& out, Graph graph) {
  // DONE FOR YOU
  out << graph.nodes.size() << " Nodes:" << endl;
  out << "[";
  for (vector<Node*>::iterator it = graph.nodes.begin();
       it != graph.nodes.end(); it++) {
    Node* n = *it;
    out << *n << ", ";
  }
  out << "]" << endl;
  out << graph.edges.size() << " Edges:" << endl;
  out << "[";
  for (vector<Edge*>::iterator it = graph.edges.begin();
       it != graph.edges.end(); it++) {
    Edge* e = *it;
    out << *e << ", ";
  }
  out << "]";
  return out;
}

// what is a helper function that turns a constant (e.g. WHITE or
// FORWARD_EDGE) into a string for debugging goodness.
string what(int& v) {
  // DONE FOR YOU
  string ret = "Unknown";
  if (v == WHITE) {
    ret = "white";
  } else if (v == GRAY) {
    ret = "gray";
  } else if (v == BLACK) {
    ret = "black";
  } else if (v == UNDISCOVERED_EDGE) {
    ret = "undiscovered";
  } else if (v == TREE_EDGE) {
    ret = "tree";
  } else if (v == BACK_EDGE) {
    ret = "back";
  } else if (v == FORWARD_EDGE) {
    ret = "forward";
  } else if (v == CROSS_EDGE) {
    ret = "cross";
  }
  return ret;
}

// make_dot generates a dotfile string for viewing your graph. Have
// tick() print out the results of this function, and then use
// http://www.webgraphviz.com/ (or get a copy of GraphViz) to view the
// result. If you're stuck, this can help you get un-stuck.
string make_dot(Graph* g) {
  // DONE FOR YOU
  stringstream ss;
  vector<Node*> nodes = g->getNodes();
  vector<Edge*> edges = g->getEdges();
  string gt = "graph";
  string con = "--";
  if (g->isDirected()) {
    con = "->";
    gt = "digraph";
  }
  ss << gt << " homework {" << endl;
  int c, dt, ft, r;
  string textColor = "black";
  for (auto it = nodes.begin(); it != nodes.end(); ++it) {
    Node* n = *it;
    n->getDiscoveryInformation(c, dt, ft, r);
    if (c == BLACK) {
      textColor = "white";
    } else {
      textColor = "black";
    }
    ss << "  " << n->getData() << " [ style=\"filled\" fontcolor=\""
       << textColor << "\" fillcolor=\"" << what(c) << "\""
       << " ]" << endl;
  }

  string edgeColor = "black";
  for (auto it = edges.begin(); it != edges.end(); ++it) {
    Edge* e = *it;
    if (e->getType() == TREE_EDGE) {
      edgeColor = "black";
    } else if (e->getType() == FORWARD_EDGE) {
      edgeColor = "purple";
    } else if (e->getType() == BACK_EDGE) {
      edgeColor = "blue";
    } else if (e->getType() == CROSS_EDGE) {
      edgeColor = "green";
    } else {
      edgeColor = "gray";
    }
    ss << "  " << e->getStart()->getData() << con << e->getEnd()->getData()
       << " [color=\"" << edgeColor << "\"]" << endl;
  }
  ss << "}" << endl;
  return ss.str();
}