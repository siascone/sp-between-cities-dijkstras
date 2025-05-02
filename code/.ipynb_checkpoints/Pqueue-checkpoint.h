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
    vector<Node*> getHeap();
    void insert(Node* node);
    Node* getAndDeleteMin();
    bool isEmpty();
    void updateNodeWeight(Node* node);
    void swap(int i, int j);
    void bubbleUp(int i);
    void bubbleDown(int i);
};

#endif // PQUEUE_H__
