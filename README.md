# Shortest Path Finder with Dijkstra’s Algorithm

A simple C++ application that finds the shortest path between cities using Dijkstra’s Algorithm on a weighted, bidirectional graph.

## 🚀 Motivation

Mapping and navigation systems are fascinating examples of real-world graph applications. This project explores how shortest path algorithms power those systems. By implementing Dijkstra’s algorithm from scratch, this project serves as a hands-on deep dive into graph theory, pathfinding, and C++ data structures.

## 🧠 What It Does

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

#### `Edge`
Represents a road between two cities.
- Stores: pointers to start/end cities and weight
- Methods: accessors/mutators

#### `Pqueue`
Custom min-priority queue for efficient node selection in Dijkstra's algorithm.
- Based on a vector-backed binary heap
- Includes: insert, get/delete min, update weight, bubbling helpers

#### `Graph`
Manages all nodes and edges.
- Methods:
  - `addNode`, `addEdge`
  - `getAdjacentEdges(Node*)`
  - `computeShortestPath(Node* start, Node* end)`
  - `buildPath(Node*)` – traces back through parents

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

## 🌟 Stretch Features
- Load actual city/road data from external file (e.g. CSV)
- Display ASCII art of the graph and path
- Implement support for alternate (2nd shortest) routes

## 📚 Key Concepts

- **Dijkstra’s Algorithm**: Greedy algorithm for finding shortest paths in weighted graphs
- **Min-Heap**: Used to efficiently retrieve the node with the lowest tentative distance
- **Graphs**: Represented using adjacency lists with nodes and weighted edges

## ⚠️ Technical Hurdles

- Efficiently updating node priorities in the heap
- Correct memory management and ownership in C++
- Debugging graph traversal logic and edge cases

## ✨ Why It’s Interesting

Shortest path problems show up in GPS routing, networking, logistics, and more. Building this project from scratch makes those concepts tangible and opens the door to exploring advanced topics like A*, heuristics, or dynamic graph data.

---
