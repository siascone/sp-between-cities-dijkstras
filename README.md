# Shortest Path Finder with Dijkstra’s Algorithm

A simple C++ application that finds the shortest path between cities using Dijkstra’s Algorithm on a weighted, bidirectional graph.

## 🚀 Motivation and Interests

--->TODO: Rewrite motivation and intersts<---

Mapping and navigation systems are fascinating examples of real-world graph applications. This project explores how shortest path algorithms power those systems. By implementing Dijkstra’s algorithm from scratch, this project serves as a hands-on deep dive into graph theory, pathfinding, and C++ data structures.

Shortest path problems show up in GPS routing, networking, logistics, and more. Building this project from scratch makes those concepts tangible and opens the door to exploring advanced topics like A*, heuristics, or dynamic graph data.

## 🧠 What It Does

--->TODO: Provide more detail here<---

- Represents cities as nodes in a graph
- Represents roads as weighted edges (distance between cities)
- Uses Dijkstra’s algorithm to compute the shortest path between two cities
- Outputs:
  - Total distance of the shortest path
  - Sequence of cities along that path

## 🏗️ Project Structure

### Core Classes

#### `Node`
Represents a city in the graph.
- Stores: name, distance, visited state, parent pointer, index in priority queue
- Methods: accessors/mutators for all fields

```cpp
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
```

#### `Edge`
Represents a road between two cities.
- Stores: pointers to start/end cities and weight
- Methods: accessors/mutators

```cpp
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
        double getWeight(); // get edge weight
        void setWeight(int val); // setter for edge weight
    };
```

#### `Pqueue`
Custom min-priority queue for efficient node selection in Dijkstra's algorithm.
- Based on a vector-backed binary heap
- Includes: insert, get/delete min, update weight, bubbling helpers

```cpp
    class Pqueue {
    private:
        vector<Node*> heap;

    public:
        Pqueue(); // constructor
        ~Pqueue(); // deconstructor
        vector<Node*> getHeap(); // getter for heap
        void insert(Node* node); // insert a node into the heap
        Node* getAndDeleteMin(); // retreive and remove min ele of heap
        bool isEmpty(); // check if heap is empty
        void updateNodeWeight(Node* node); // update node weight and position in heap
        void swap(int i, int j); // swap two elements of heap
        void bubbleUp(int i); // bubble up ele at index i in heap
        void bubbleDown(int i); // bubble down ele at index i in heap
    };
```

#### `Graph`
Manages all nodes and edges.
- Methods:
  - `addNode`, `addEdge`
  - `getAdjacentEdges(Node*)`
  - `computeShortestPath(Node* start, Node* end)`
  - `buildPath(Node*)` – traces back through parents
  
```cpp
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
```

## 📚 Key Concepts

--->TODO: Elaborate on each key concept and discuss provided code<---


- **Dijkstra’s Algorithm**: Greedy algorithm for finding shortest paths in weighted graphs

```cpp
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
```

- **Min-Heap Priority Queue**: Used to efficiently retrieve the node with the lowest tentative distance 

```cpp
    void Pqueue::bubbleUp(int i) {

        int idx = i;

        while (idx > 0) {
            int parent_idx = (idx - 1) / 2;

            if (heap[idx]->getDist() < heap[parent_idx]->getDist()) {
                swap(idx, parent_idx);
                idx = parent_idx;
            } else {
                break;
            }
        }

    }

    void Pqueue::bubbleDown(int i) {
        int idx = i;
        int n = heap.size();

        while (true) {
            // get indexes of left and right childern of idx
            int left_child_idx = (2 * idx) + 1;
            int right_child_idx = (2 * idx) + 2;

            // assume idx will be the idx of the smaller value d
            int smaller = idx;

            // update smaller based on sp of left and right children
            if (left_child_idx < n && heap[left_child_idx]->getDist() < heap[smaller]->getDist()) {
                smaller = left_child_idx;
            }

            if (right_child_idx < n && heap[right_child_idx]->getDist() < heap[smaller]->getDist()) {
                smaller = right_child_idx;
            }

            // if smaller isn't idx swap
            if (smaller != idx) {
                swap(idx, smaller);
                idx = smaller;
            } else {
                break;
            }
        } 
    }
```

- **Graphs**: Represented using adjacency lists with nodes and weighted edges

```cpp
    // TODO Add example node and edge vectors...
```

## ✅ Current Status

- ✅ All four core classes (`Node`, `Edge`, `Pqueue`, `Graph`) implemented
- ✅ Unit and integration tests completed with TDD
- ✅ Dijkstra's algorithm correctly computes shortest paths

## 🛠️ Next Steps (Planned UI)
- Add CLI interface:
  - Display a list of 12 local cities
  - Allow user to choose a start and end city
  - Output the total distance and list of cities along the shortest route
  - Prompt user to search again or exit
  
## ⚠️ Technical Hurdles

--->TODO: Expand on experience with these technical hurdles<---


- Efficiently updating node priorities in the heap
- Correct memory management and ownership in C++
- Debugging graph traversal logic and edge cases

## 🌟 Future Features

--->TODO: Explore other possible features and reorder based on feasibility<---

- Load actual city/road data from external file (e.g. CSV)
- Display ASCII art of the graph and path
- Implement support for alternate (2nd shortest) routes

---
