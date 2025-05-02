#include "pq.h"

PriorityQueue::PriorityQueue() {}

PriorityQueue::~PriorityQueue() {}

void PriorityQueue::insert(Node* node) {

}

Node* PriorityQueue::getAndDeleteMin() {
    return nullptr
}

bool PriorityQueue::isEmpty() {

    return True
}

void PriorityQueue::updateNodeWeight(node) {

}

void PriorityQueue::swap(int i, int j) {

}

void PriorityQueue::bubbleUp(int i) {

}

void PriorityQueue::bubbleDown(int i) {

}

// class PriorityQueue:
//     # Constructor: 
//     def __init__(self):
//         self.heap = [] 
        
//     def insert(self, v):
//         self.heap.append(v) # add to end of heap array
//         v.idx_in_priority_queue = len(self.heap) - 1 # set idx to end of heap
//         self.bubble_up(v.idx_in_priority_queue) # bubble up to correct position
    
//     def get_and_delete_min(self):
//         if self.is_empty():
//             return None # nothing to return
        
//         # get min element
//         min_vrtx = self.heap[0]
        
//         # move last ele of heap to front and bubble down
//         last_vrtx = self.heap.pop()
        
//         if not self.is_empty():
//             self.heap[0] = last_vrtx
//             last_vrtx.idx_in_priority_queue = 0
//             self.bubble_down(0)
            
//         min_vrtx.idx_in_priority_queue = -1 # mark min no longer in heap
        
//         return min_vrtx
    
//     def is_empty(self):
//         return len(self.heap) == 0
        
//     def update_vertex_weight(self, v):
//         # new weight has been found for v, bubble up from old idx
//         self.bubble_up(v.idx_in_priority_queue)
        
//     def swap(self, i, j):
//         # swap verts
//         self.heap[i], self.heap[j] = self.heap[j], self.heap[i]
        
//         # update idx in queue
//         self.heap[i].idx_in_priority_queue = i
//         self.heap[j].idx_in_priority_queue = j
    
//     def bubble_up(self, idx):
//         while idx > 0: # not min idx
//             pi_idx = (idx - 1) // 2 # find parent idx
//             if self.heap[idx].d < self.heap[pi_idx].d: # sp dist of parent is greater
//                 self.swap(idx, pi_idx)
//                 idx = pi_idx
//             else:
//                 break
                
            
//     def bubble_down(self, idx):
//         n = len(self.heap)
        
//         while True:
//             #get indexes of left and right childern of idx
//             left = (2 * idx) + 1
//             right = (2 * idx) + 2
            
//             # assume idx will be the idx of the smaller value d
//             smaller = idx
        
//             # update smaller based on sp of left and right children
//             if left < n and self.heap[left].d < self.heap[smaller].d:
//                 smaller = left
            
//             if right < n and self.heap[right].d < self.heap[smaller].d:
//                 smaller = right
            
//             # if smaller isn't idx swap
//             if smaller != idx:
//                 self.swap(idx, smaller)
//                 idx = smaller
//             else:
//                 break