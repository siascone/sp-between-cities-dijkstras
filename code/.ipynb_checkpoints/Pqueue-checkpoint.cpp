#include "Pqueue.h"
#include <iostream>
#include <vector>

Pqueue::Pqueue() {}

Pqueue::~Pqueue() {}

vector<Node*> Pqueue::getHeap() {
    return heap;
}

void Pqueue::insert(Node* node) {
//  self.heap.append(v) # add to end of heap array
//  v.idx_in_priority_queue = len(self.heap) - 1 # set idx to end of heap
//  self.bubble_up(v.idx_in_priority_queue) # bubble up to correct position
    
    heap.push_back(node);
    node->setIdxInPQ(heap.size() - 1);
    int idx = node->getIdxInPQ();
    cout << "index in pq: " << node->getIdxInPQ() << endl;
    bubbleUp(idx);
}

Node* Pqueue::getAndDeleteMin() {
//     if self.is_empty():
//         return None # nothing to return

//     # get min element
//     min_vrtx = self.heap[0]

//     # move last ele of heap to front and bubble down
//     last_vrtx = self.heap.pop()

//     if not self.is_empty():
//         self.heap[0] = last_vrtx
//         last_vrtx.idx_in_priority_queue = 0
//         self.bubble_down(0)

//     min_vrtx.idx_in_priority_queue = -1 # mark min no longer in heap

//     return min_vrtx
    return nullptr;
}

bool Pqueue::isEmpty() {
    // return len(self.heap) == 0
    return true;
}

void Pqueue::updateNodeWeight(Node* node) {
    // new weight has been found for v, bubble up from old idx
    // self.bubble_up(v.idx_in_priority_queue)

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
//     n = len(self.heap)

//     while True:
//         #get indexes of left and right childern of idx
//         left = (2 * idx) + 1
//         right = (2 * idx) + 2

//         # assume idx will be the idx of the smaller value d
//         smaller = idx

//         # update smaller based on sp of left and right children
//         if left < n and self.heap[left].d < self.heap[smaller].d:
//             smaller = left

//         if right < n and self.heap[right].d < self.heap[smaller].d:
//             smaller = right

//         # if smaller isn't idx swap
//         if smaller != idx:
//             self.swap(idx, smaller)
//             idx = smaller
//         else:
//             break
}
        