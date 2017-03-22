#ifndef WORDSEARCH_HEAP_H
#define WORDSEARCH_HEAP_H

#include <vector>
#include <string>

using namespace std;

template <typename T>
class heap {
public:
    heap(int size);
    int left(int n);
    int right(int n);
    int parent(int n);
    T getIten(int n);
    void initializeMaxHeap(vector<T> v);
    void maxHeapify(int i, int max);
    void buildMaxHeap();
    vector <T> heapSort();

private:
    std::vector<T> maxHeap;
    int size;
};

template <typename T>
heap<T>::heap(int n): maxHeap(n), size(n) {}

template <typename T>
int heap<T>::left(int n) {
    return n * 2; //may be out of the index of the heap
}

template <typename T>
int heap<T>::right(int n) {
    return (n * 2) + 1; //may be out of the index of the heap
}

template <typename T>
void heap<T>::initializeMaxHeap(vector<T> v){
    for(int i = 0; i < v.size(); i++){
        maxHeap.at(i+1) = v.at(i);
    }
    buildMaxHeap();
}

template <typename T>
void heap<T>::buildMaxHeap() {
    int heapFloor = size/2;

    for(int i = heapFloor; i > 0; i--){
        maxHeapify(i, size);
    }
}

template <typename T>
void heap<T>::maxHeapify(int i, int max) {
    int left = heap::left(i);
    int right = heap::right(i);
    int largest = i;

    if(left < max && maxHeap.at(left) > maxHeap.at(largest)){  //check both child branches
        largest = left;
    }
    if(right < max && maxHeap.at(right) > maxHeap.at(largest)){
        largest = right;
    }

    if(largest != i){
        swap(maxHeap.at(i), maxHeap.at(largest)); //swap parent with the largest child
        maxHeapify(largest, max);
    }
}

template <typename T>
vector<T> heap<T>::heapSort() {
    int end = size - 1;
    vector<T> temp;

    while(end > 1){
        swap(maxHeap.at(end), maxHeap.at(1));
        end--;
        maxHeapify(1, end);
    }

    for(int i = 1; i < size; i++){
        temp.push_back(maxHeap.at(i));
    }

    return temp;
}


#endif //WORDSEARCH_HEAP_H
