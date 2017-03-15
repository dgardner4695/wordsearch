#include "heap.h"

#include <vector>


using namespace std;

template <typename T>
int heap<T>::left(int n) {
  return n * 2; //may be out of the index of the heap
}

template <typename T>
int heap<T>::right(int n) {
    return (n * 2) + 1; //may be out of the index of the heap
}

template <typename T>
void heap<T>::initializeMaxHeap(vector<T> v) {
    this->maxHeap = v;
    //buildHeap
}

template <typename T>
void heap<T>::buildMaxHeap() {

}

template <typename T>
void heap<T>::maxHeapify() {

}