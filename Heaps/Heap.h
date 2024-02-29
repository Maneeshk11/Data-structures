#pragma once

#include <bits/stdc++.h>
using namespace std;

template <typename T> 
class Heap {
    public:
        Heap() : capacity_(2), size_(0), array_(new T[capacity_ + 1]) {}
        Heap(vector<T>arr) : Heap(){
            buildHeap(arr);
        }
        Heap(vector<T>arr, bool isMinheap) : Heap(){
            isMinHeap_ = isMinheap;
            buildHeap(arr);
        }
        void insert(T value);
        void removeMin(); 
        void removeMax(); 
        void buildHeap(vector<T> & array);
        void heapifyUp(int index);
        void heapifyDown(int index);
        void swapElements(int index1, int index2);
        void growArray();
        void printHeapArray();
    private:
        int capacity_;
        int size_;
        T* array_;
        bool isMinHeap_ = true; // Determines where the heap is min or max. Default is min heap.
};

#include "Heap.hpp"