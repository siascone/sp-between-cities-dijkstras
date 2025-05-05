# Shortest Path Finder with Dijkstra’s Algorithm

A simple C++ application that finds the shortest path between cities using 
Dijkstra’s Algorithm on a weighted, bidirectional graph.

## 🚀 Motivation and Interests

Mapping and navigation systems are compelling real-world applications of graph 
theory. This project explores how shortest path algorithms—like Dijkstra’s—form 
the backbone of such systems. By implementing Dijkstra’s algorithm from scratch, 
the project offers a hands-on dive into graph traversal and pathfinding.

My interest in graphs and navigation stems from countless hours spent in the 
saddle, exploring routes with my bike computer. While the full complexity of 
modern bike mapping systems goes far beyond this project, their foundations lie 
in the same algorithms and concepts explored here. This project makes those 
fundamentals tangible and sets the stage for deeper exploration of topics like 
A*, heuristics, and dynamic graphs.

## 🧠 What It Does

This project simulates a simplified map system by modeling cities and the roads 
that connect them as a weighted graph. It allows users to calculate the shortest 
travel route between two cities using Dijkstra’s algorithm. The program focuses 
on demonstrating core concepts of graph representation and pathfinding.

- Models a network of cities as nodes in a graph
- Represents roads as weighted edges, where weights correspond to distances 
  between cities
- Implements Dijkstra’s algorithm to determine the shortest path between any two 
  cities in the graph
- Outputs:
  - The ordered list of cities along the path
  - Total distance of the shortest path

## Getting Setup and Running the Program

1. Clone this repo
- Navigate to project directory
3. Setup and test application:
-  cd into the /build folder and run the following commands:
  - `cmake ..`
  - `make`
  - `./run_tests` (make sure all 24 tests are passing)
3. Run the application:
- open app/main.cpp
  - comment in the 4 .cpp inclusions for Node, Edge, Graph and Pqueue
- cd into the /app folder and run the following commands:
  - `g++ main.cpp -o main` (compile the application)
  - `./main` (run the application)
  
Note: If you would like to run the test suite after running the main file 
remember to comment out the 4 .cpp inclusions for Node, Edge, Graph and Pqueue

## Project Structure

### Core Classes (linked to corresponding header files)

#### [Node](code/Node.h)

Represents a city in the graph.
- Stores: name, distance, visited state, parent pointer, index in priority queue
- Includes:
  - getter for name
  - getters/setters for all other fields

#### [Edge](code/Edge.h)

Represents a road between two cities.
- Stores: pointers to start/end cities (nodes) and weight
- Includes:
  - getters for start and end cities
  - getters/setters for weight

#### [Pqueue](code/Pqueue.h)

Custom min-heap priority queue for efficient node selection in Dijkstra's 
algorithm.
- Based on a vector-backed binary heap
- Includes:
  - insert
  - get and delete min
  - update weight
  - bubbling helpers

#### [Graph](code/Graph.h)

Manages all nodes and edges.
- Methods:
  - `addNode`, `addEdge` - adds a node or edge to the graph
  - `getAdjacentEdges(Node*)` - returns all edges with a given node as the start 
     node
  - `computeShortestPath(Node* start, Node* end)` - implementation of Dijkstra's 
    algorithm
  - `buildPath(Node*)` – traces back through parents
  
## Key Concepts

### 1. **Dijkstra’s Algorithm**:

Dijkstra’s Algorithm is a classic greedy algorithm used to find the shortest 
path between nodes in a weighted graph with non-negative edge weights. It 
systematically explores paths from a starting node, always selecting the node 
with the lowest known distance from the start, and updates neighboring nodes 
with shorter paths when found. This process continues until the shortest paths 
to all reachable nodes have been determined.

In the case of this project, everytime a node is relaxed the node's parent is 
updated as well. This way from any given end node (city) the shortest path can 
be calculated by simply followoing the chain of parents until we reach a node 
with a NULL parent which will always be the given start node (city). 

- Key Characteristics:
  - Uses a priority queue to always process the closest unvisited node.
  - Keeps track of the current shortest know distancs to each node and the 
    parent node from which that distance was calculated
  - Whenever a shorter path to a node is discovered, the algorithm relaxes the 
    edge - updating the node's distance and parent
   
The code below is the implimentation of Dijkstra's Algorithm used in this project

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
### 2. **Min-Heap Priority Queue**: 

A Min-Heap Priority Queue is a data structure that allows for the efficient 
retrieval of the element with the lowest value. In the case of this project we 
are considering the node with the smallest tentative distance from the starting 
point. 

In Dijkstra’s algorithm, the priority queue ensures that the next node visited 
is always the one closest to the start node based on current known distances. 
- This behavior is crucial to the algorithm's greedy approach: by always 
  expanding the nearest unvisited node, it guarantees that the shortest paths 
  are found incrementally and efficiently.
- The priority queue supports fast insertion, removal, and updating (or 
  "bubbling up/down") of nodes as better paths are discovered during execution.

### 3.  **Graph**: 

In this project, the graph is represented using separate vectors for nodes and 
edges, rather than a pre-built adjacency list. Instead, adjacency-like behavior 
is constructed dynamically during traversal: 
- When a node is dequeued from the priority queue, the program locates all edges
  that originate from that node and processes their corresponding destination 
  nodes.

This structure supports Dijkstra’s algorithm as follows:

- Nodes represent cities and store metadata like distance, visited status, and 
  parent.
- Edges represent roads, containing a weight (distance) and pointers to the 
  start and end nodes.
- During execution, the graph locates all outgoing edges from the current node 
  to identify neighbors.
- The algorithm then relaxes these neighbors—updating distances and queue 
  positions if a shorter path is found.
- The priority queue ensures that the next node selected for exploration is 
  always the one with the lowest known distance from the start.

This approach maintains flexibility while still supporting efficient graph traversal and shortest path computation.

The image below is a visual representation of the main graph used for testing 
and the underlying structure in the user interface.



## Current Status

- ✅ All four core classes (`Node`, `Edge`, `Pqueue`, `Graph`) implemented

- ✅ Unit and integration tests completed with TDD and (red, green, refactor)

- ✅ Dijkstra's algorithm correctly computes shortest paths
  - Test case of small graph with 5 nodes 12 edges
  - Test case of large graph with 12 nodes and 56 edges

- ✅ CLI interface
  -  Displays a list of 12 local cities
  -  Allow's user to choose a start and end city
  -  Outputs list of cities along the shortest route and total distance
  -  Prompts user to search again or exit the program
  
## Technical Hurdles

- **Priority Queue Behavior:**
  Initially anticipated as a major challenge, priority queue behavior turned out
  to be relatively straightforward thanks to the deep understanding gained 
  during class. Implementing efficient updates—especially when better paths were
  found—was manageable and worked as expected in practice.

- **C++ Memory and Ownership**:
  Navigating memory management in C++ was a valuable learning experience. A key
  insight came from exploring how destructors work within classes. Once an 
  object created with `new` was no longer in use, the class’s destructor 
  automatically handled cleanup. 
  
  At one point, I incorrectly suspected a memory leak and attempted to manually 
  delete objects, which led to runtime errors—those objects had already been 
  cleaned up. This reinforced the importance of understanding object lifetimes 
  and trusting properly implemented destructors.

- **Debugging Traversal**:
  Graph traversal bugs surfaced during testing, especially when scaling up. A 
  small graph passed initial tests, but a larger map revealed routing failures 
  where expected paths were unreachable. 
  
  After reviewing the problem, I discovered that although I had correctly added 
  all directed edges, I had overlooked the need for bidirectional edges. My test
  map represented an undirected graph, and I was only allowing one-way travel 
  between nodes. Updating the graph to support two-way connections resolved the 
  issue, validated the shortest path results, and turned the earlier false 
  positives into useful debugging insights.

## 🌟 Future Features

- Visualization: Output the graph to the UI via ASCII art map.
- Multiple Routes: Implement support for alternate (2nd shortest) routes
- Graph Input from File: Load existing city/road data from external resource 
  (e.g. CSV)

---
