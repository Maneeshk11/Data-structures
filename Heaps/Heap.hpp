
#include <bits/stdc++.h>
#include "Heap.h"

using namespace std;

template <typename T>
void Heap<T>::buildHeap(vector<T> & array) {
    if (array.size() > capacity_) {
        T* newArray = new T[array.size() + 1];
        array_ = newArray;
        capacity_ = 2 * array.size();
        size_ = array.size();
        for (int i=0; i<array.size(); i++) {
            array_[i] = array[i];
            heapifyUp(i);
        }
    }
}

template <typename T>
void Heap<T>::heapifyUp(int index) {
    if (isMinHeap_) { // for min heap
        if (index == 0 || array_[(index + 1)/2 - 1] <= array_[index]) { 
            return;
        }
        else {
            swapElements((index + 1)/2 - 1, index);
        }
        heapifyUp((index + 1)/2 - 1);
    } else { // for max heap
        if (index == 0 || array_[(index + 1)/2 - 1] >= array_[index]) { 
            return;
        }
        else {
            swapElements((index + 1)/2 - 1, index);
        }
        heapifyUp((index + 1)/2 - 1);
    }
}

template <typename T>
void Heap<T>::heapifyDown(int index) {
    if (2*(index+1) > size_) {
        return;
    }
    if (isMinHeap_) {
        if (array_[2*(index+1)-1] < array_[index]) {
            swapElements(2*(index+1)-1, index);
            heapifyDown(2*(index+1)-1);
        } else if (2*(index+1)+1 > size_ && array_[2*(index+1)] < array_[index]) {
            swapElements(2*(index+1), index);
            heapifyDown(2*(index+1));
        } 
    } else {
        if (array_[2*(index+1)-1] > array_[index]) {
            swapElements(2*(index+1)-1, index);
            heapifyDown(2*(index+1)-1);
        } else if (2*(index+1)+1 > size_ && array_[2*(index+1)] > array_[index]) {
            swapElements(2*(index+1), index);
            heapifyDown(2*(index+1));
        } 
    }
}

template <typename T>
void Heap<T>::insert(T val) {
    if (size_ == capacity_) {
        growArray();
    }
    size_++;
    array_[size_-1] = val;
    heapifyUp(size_-1);  
}

template <typename T>
void Heap<T>::removeMin() { // removes the top of min-heap.
    if (!isMinHeap_) {
        cout << "Max heap does not support the operation: removeMin()" << endl;
    }
    if (size_ == 0) {
        cout << "Can't remove element as heap is empty" << endl;
        return;
    }
    array_[0] = array_[size_ - 1];
    size_--;
    heapifyDown(0);
}

template <typename T>
void Heap<T>::removeMax() { // removes the top of max-heap.
    if (isMinHeap_) {
        cout << "Min heap does not support the operation: removeMax()" << endl;
    }
    if (size_ == 0) {
        cout << "Can't remove element as heap is empty" << endl;
        return;
    }
    array_[0] = array_[size_ - 1];
    size_--;
    heapifyDown(0);
}

// -------------- Helper functions --------------

template <typename T>
void Heap<T>::swapElements(int index1, int index2) {
    T val = array_[index1];
    array_[index1] = array_[index2];
    array_[index2] = val;
    return;
}

template<typename T>
void Heap<T>::growArray() {
    capacity_ = capacity_ * 2 + 1;
    T* newArray = new T[capacity_];
    for (int i=0; i<size_; i++) {
        newArray[i] = array_[i];
    }
    array_ = newArray;
    return;
}

template <typename T>
void Heap<T>::printHeapArray() { // print the heap as an array.
    if (size_ == 0) {
        cout << "Heap is empty" << endl;
        return;
    } 
    for (int i=0; i<size_; i++) {
        cout << array_[i] << " ";
    }  
    cout << endl;
    return;
}

