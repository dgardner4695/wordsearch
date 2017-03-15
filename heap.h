#ifndef WORDSEARCH_HEAP_H
#define WORDSEARCH_HEAP_H

#include <vector>

template <typename T>
class heap {
public:
    int left(int n);
    int right(int n);
    int parent(int n);
    T getIten(int n);
    void initializeMaxHeap(std::vector<T> v);
    void maxHeapify();
    void buildMaxHeap();
    void heapSort();

private:
    std::vector<T> maxHeap;
};


#endif //WORDSEARCH_HEAP_H
