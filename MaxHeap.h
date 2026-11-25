#pragma once
#include <vector>
#include "WordInfo.h"

class MaxHeap {
public:
    MaxHeap();
    MaxHeap(const std::vector<WordInfo*>& arr);

    void push(WordInfo* item);
    WordInfo* top() const;
    void pop();

    bool empty() const;
    int size() const;

private:
    std::vector<WordInfo*> heap;

    void heapifyUp(int i);
    void heapifyDown(int i);
};