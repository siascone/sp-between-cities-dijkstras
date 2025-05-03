// If you change anything in this file, your changes will be ignored
// in your homework submission.
// Chekout TEST_F functions bellow to learn what is being tested.
#include <cmath>
#include <ctime>
#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <math.h>
#include <string>

// in order to access private members, we have to defeat the safety
// mechanisms. This is acceptable for unit testing, but not much
// else. It is also not portable because it is not supported by the
// C++ spec, and therefore might not work with all compilers.
#define private public
#include "../code/Edge.h"
#include "../code/Graph.h"
#include "../code/Node.h"
#include "../code/Pqueue.h"
#include "graph_builders.cpp"

using namespace std;


// Node Unit Tests

class NodeTest : public ::testing::Test {
protected:
    Node* test_node; // default object for node unit tests

    void SetUp() override {
        test_node = new Node("Boulder");
    }

    void TearDown() override {}
};

TEST_F(NodeTest, ConstructorInitializesName) {
    EXPECT_EQ(test_node->getName(), "Boulder");
}

TEST_F(NodeTest, ConstructorInitializesDistToInfinity) {
    EXPECT_EQ(test_node->getDist(), numeric_limits<double>::infinity());
}

TEST_F(NodeTest, ConstructorInitializesVisitedToFalse) {
    EXPECT_EQ(test_node->isVisited(), false);
}

TEST_F(NodeTest, ConstructorInitializesParentToNull) {
    EXPECT_EQ(test_node->getParent(), nullptr);
}

TEST_F(NodeTest, SetsDistanceCorrectly) {
    test_node->setDist(100.1);
    EXPECT_EQ(test_node->getDist(), 100.1);
}

TEST_F(NodeTest, SetsVisitedCorrectly) {
    test_node->setVisited(true);
    EXPECT_EQ(test_node->isVisited(), true);
}

TEST_F(NodeTest, SetsParent) {
    Node* parent_node = new Node("Longmont");
    test_node->setParent(parent_node);
    EXPECT_EQ(test_node->getParent(), parent_node);
}

TEST_F(NodeTest, TestSetIdxIn) {
    EXPECT_EQ(test_node->getIdxInPQ(), -1);
    test_node->setIdxInPQ(123);
    EXPECT_EQ(test_node->getIdxInPQ(), 123);
}

// Edge/Node Integration Tests
class EdgeTest : public ::testing::Test {
protected:
    Edge* test_edge; // default object for edge unit tests
    Node* node_a;
    Node* node_b; 
    
    void SetUp() override {
        node_a = new Node("Boulder");
        node_b = new Node("Longmont");
        test_edge = new Edge(node_a, node_b, 3);
    }

    void TearDown() override {}
};

TEST_F(EdgeTest, InitializeAndGetNodeA) {
    EXPECT_EQ(test_edge->getNodeA(), node_a);
}

TEST_F(EdgeTest, InitializeAndGetNodeB) {
    EXPECT_EQ(test_edge->getNodeB(), node_b);
}

TEST_F(EdgeTest, InitializeAndGetWeight) {
    EXPECT_EQ(test_edge->getWeight(), 3);
}

TEST_F(EdgeTest, CorrectlySetsNewEdgeWeight) {
    test_edge->setWeight(2); // relax edge from 3 to 2
    EXPECT_EQ(test_edge->getWeight(), 2);
}

// PQueue/Edge/Node integration Tests

class PQTest : public ::testing::Test {
protected:
    
    Pqueue* test_pq;
    Node* boulder;
    
    void SetUp() {
        test_pq = new Pqueue();
        boulder = new Node("boulder");
    }
    
    void TearDown() {}
    
};

TEST_F(PQTest, TestInsertAddsNodeToQueue) {
    EXPECT_EQ(test_pq->getHeap().size(), 0);
    test_pq->insert(boulder);
    EXPECT_EQ(test_pq->getHeap().size(), 1);
    EXPECT_EQ(test_pq->getHeap()[0], boulder);
}

TEST_F(PQTest, TestSwap) {
    Node* longmont = new Node("Longmont");
    test_pq->insert(boulder);
    test_pq->insert(longmont);

    EXPECT_EQ(test_pq->getHeap()[0], boulder);
    EXPECT_EQ(test_pq->getHeap()[1], longmont);
    
    test_pq->swap(0, 1);
    
    EXPECT_EQ(test_pq->getHeap()[1], boulder);
    EXPECT_EQ(test_pq->getHeap()[0], longmont);
    
}

TEST_F(PQTest, TestInsertBubblesNodeUp) {
    // EXPECT_EQ(false, true);
    Node* longmont = new Node("Longmont");
    Node* niwot = new Node("Niwot");
    
    longmont->setDist(3);
    niwot->setDist(2);
    boulder->setDist(1);
    
    test_pq->insert(longmont);
    test_pq->insert(niwot);
    test_pq->insert(boulder);
    
    vector<Node*> heap = test_pq->getHeap();
    
    EXPECT_EQ(heap[0], boulder);
}

TEST_F(PQTest, TestUpdateNodeWeight) {
    Node* longmont = new Node("Longmont");
    Node* niwot = new Node("Niwot");
    
    longmont->setDist(3);
    niwot->setDist(2);
    boulder->setDist(1);
    
    test_pq->insert(longmont);
    test_pq->insert(niwot);
    test_pq->insert(boulder);
        
    EXPECT_EQ(test_pq->getHeap()[0], boulder);
    
    niwot->setDist(0);
    test_pq->updateNodeWeight(niwot);
    
    EXPECT_EQ(test_pq->getHeap()[0], niwot);
}

TEST_F(PQTest, TestPQIsEmpty) {
    EXPECT_EQ(test_pq->getHeap().size(), 0);
    test_pq->insert(boulder);
    EXPECT_NE(test_pq->getHeap().size(), 0);
}

TEST_F(PQTest, TestBubbleDown) {
    Node* longmont = new Node("Longmont");
    Node* niwot = new Node("Niwot");
    
    longmont->setDist(3);
    niwot->setDist(2);
    boulder->setDist(1);
    
    test_pq->insert(longmont);
    test_pq->insert(niwot);
    test_pq->insert(boulder);
    
    EXPECT_EQ(test_pq->getHeap()[0], boulder);
    
    boulder->setDist(5);
    
    test_pq->bubbleDown(boulder->getIdxInPQ());
    
    int endIdx = test_pq->getHeap().size() - 1;
    
    EXPECT_EQ(test_pq->getHeap()[0], niwot);
    EXPECT_EQ(test_pq->getHeap()[endIdx], boulder);
}

TEST_F(PQTest, TestGetAndDeleteMin) {
    Node* longmont = new Node("Longmont");
    Node* niwot = new Node("Niwot");
    Node* hygiene = new Node("Hygiene");
    
    hygiene->setDist(4);
    longmont->setDist(3);
    niwot->setDist(2);
    boulder->setDist(1);
    
    test_pq->insert(hygiene);
    test_pq->insert(longmont);
    test_pq->insert(niwot);
    test_pq->insert(boulder);
    
    EXPECT_EQ(test_pq->getHeap()[0], boulder);
    
    Node* min = test_pq->getAndDeleteMin();
    
    EXPECT_EQ(min, boulder);
    EXPECT_NE(test_pq->getHeap()[0], boulder);
    EXPECT_EQ(test_pq->getHeap()[0], niwot);
    
}

// Graph/PQueue/Edge/Node Integration Tests
class GraphTest : public ::testing::Test {
protected:
    
    Graph* test_graph;
    Node* boulder;
    Node* hygiene;
    Edge* boulder_hygiene;
    
    void SetUp() {
        test_graph = new Graph();
        boulder = new Node("Boulder");
        hygiene = new Node("Hygiene");
        boulder_hygiene = new Edge(boulder, hygiene, 3);
    }
    
    void TearDown() {}
};

TEST_F(GraphTest, TestAddAndGetNodes) {
    test_graph->addNode(boulder);
    test_graph->addNode(hygiene);
    
    EXPECT_EQ(test_graph->getNodes()[0], boulder);
    EXPECT_EQ(test_graph->getNodes()[1], hygiene);
}

TEST_F(GraphTest, TestAddAndGetEdges) {
    test_graph->addEdge(boulder_hygiene);
    
    EXPECT_EQ(test_graph->getEdges()[0], boulder_hygiene);
}

TEST_F(GraphTest, TestGetAdjacentEdges) {
    test_graph->addNode(boulder);
    test_graph->addNode(hygiene);
    test_graph->addEdge(boulder_hygiene);
    set<Edge*> adjEdges = test_graph->getAdjacentEdges(boulder);
    EXPECT_NE(adjEdges.find(boulder_hygiene), adjEdges.end());
}

// forward declaration of graph builders. See ./graph_builders.cpp
Graph* mkSmallLocalGraph();
Graph* mkLargeLocalGraph();

TEST_F(GraphTest, TestComputeShortestPathSmallBoulderToLongmont) {
    Graph* smGraph = mkSmallLocalGraph();
    vector<Node*> nodes = smGraph->getNodes();
    Node* boulder = nodes[0];
    Node* longmont = nodes[1];
    Node* niwot = nodes[3];
    
    EXPECT_EQ(longmont->getDist(), numeric_limits<double>::infinity());

    vector<Node*> sp_boulder_longmont = smGraph->computeShortestPath(boulder, longmont);
    
    EXPECT_EQ(sp_boulder_longmont.size(), 3);
    EXPECT_EQ(sp_boulder_longmont[0], boulder);
    EXPECT_EQ(sp_boulder_longmont[1], niwot);
    EXPECT_EQ(sp_boulder_longmont[2], longmont);
    
    // convert double to string for comparison
    string longmont_dist_string = to_string(longmont->getDist());
    string final_dist_string = to_string(15.8);
    
    EXPECT_EQ(longmont_dist_string, final_dist_string);
}

TEST_F(GraphTest, TestComputeShortestPathLafayetteToHygiene) {
    // sp = Lafayette => Erie => Longmont => Hygiene, 22.4
    Graph* lgGraph = mkLargeLocalGraph();
    vector<Node*> nodes = lgGraph->getNodes();
    
    Node* lafayette = nodes[7];
    Node* erie = nodes[6];
    Node* longmont = nodes[5];
    Node* hygiene = nodes[4];
    
    EXPECT_EQ(hygiene->getDist(), numeric_limits<double>::infinity());
    
    vector<Node*> sp_lafayette_hygiene = lgGraph->computeShortestPath(lafayette, hygiene);
    
    
    // cout << endl << sp_lafayette_hygiene[0]->getName() << endl;
    
    EXPECT_EQ(sp_lafayette_hygiene.size(), 4);
    EXPECT_EQ(sp_lafayette_hygiene[0], lafayette);
    EXPECT_EQ(sp_lafayette_hygiene[1], erie);
    EXPECT_EQ(sp_lafayette_hygiene[2], longmont);
    EXPECT_EQ(sp_lafayette_hygiene[3], hygiene);
    
    // convert double to string for comparison
    string hygiene_dist_string = to_string(hygiene->getDist());
    string final_dist_string = to_string(22.4);
    
    EXPECT_EQ(hygiene_dist_string, final_dist_string);
    

} 
