#ifndef PQUEUE_H__
#define PQUEUE_H__

#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;

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

#endif // PQUEUE_H__
