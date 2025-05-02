#ifndef PRIORITYQUEUE_H__
#define PRIORITYQUEUE_H__

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class PriorityQueue {
private:
    vector<Node*> heap;

public:
    PriorityQueue(); // constructor
    ~PriorityQueue(); // deconstructor
    void insert(Node* node);
    Node* getAndDeleteMin();
    bool isEmpty();
    void updateNodeWeight(node);
    void swap(int i, int j);
    void bubbleUp(int i);
    void bubbleDown(int i);
};

#endif // PRIORITYQUEUE_H__
