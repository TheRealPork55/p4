#include "MaxHeap.h"

MaxHeap::MaxHeap() {}

MaxHeap::MaxHeap(const std::vector<WordInfo*>& arr) {
    heap = arr;
    for (int i = heap.size() / 2; i >= 0; --i)
        heapifyDown(i);
}

bool MaxHeap::empty() const { return heap.empty(); }

int MaxHeap::size() const { return heap.size(); }

WordInfo* MaxHeap::top() const {
    if (heap.empty()) return nullptr;
    return heap[0];
}

void MaxHeap::push(WordInfo* item) {
    heap.push_back(item);
    heapifyUp(heap.size() - 1);
}

void MaxHeap::pop() {
    if (heap.empty()) return;
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
}

void MaxHeap::heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent]->lookupCount < heap[i]->lookupCount) {
            std::swap(heap[parent], heap[i]);
            i = parent;
        } else break;
    }
}

void MaxHeap::heapifyDown(int i) {
    int n = heap.size();
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < n && heap[left]->lookupCount > heap[largest]->lookupCount)
            largest = left;
        if (right < n && heap[right]->lookupCount > heap[largest]->lookupCount)
            largest = right;

        if (largest == i) break;

        std::swap(heap[i], heap[largest]);
        i = largest;
    }
}