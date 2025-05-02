#include "Pqueue.h"
#include <iostream>
#include <vector>

Pqueue::Pqueue() {}

Pqueue::~Pqueue() {}

vector<Node*> Pqueue::getHeap() {
    return heap;
}

void Pqueue::insert(Node* node) {
    heap.push_back(node);
    node->setIdxInPQ(heap.size() - 1);
    bubbleUp(node->getIdxInPQ());
}

Node* Pqueue::getAndDeleteMin() {
    if (isEmpty()) {
        return nullptr;
    }

    Node* min_node = heap[0];

    Node* last_node = heap.back();
    heap.pop_back(); 

    if (!isEmpty()) {
        heap[0] = last_node;
        last_node->setIdxInPQ(0);
        bubbleDown(0);
    }

    // mark min node no longer in heap
    min_node->setIdxInPQ(-1);

    return min_node;
}

bool Pqueue::isEmpty() {
    return heap.size() == 0;
}

void Pqueue::updateNodeWeight(Node* node) {
    // new weight has been found for v, bubble up from old idx
    bubbleUp(node->getIdxInPQ());

}

void Pqueue::swap(int i, int j) {
    
    Node* temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
    
    heap[i]->setIdxInPQ(i);
    heap[j]->setIdxInPQ(j);

}

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
        