#include <bits/stdc++.h>
#include "Heap.h"

using namespace std;

int main() {
    vector <int> arr = {4, 10, 3, 5, 1};
    Heap<int> heap(arr, false);
    // minheap.insert(4);
    heap.printHeapArray();
    heap.removeMax();
    heap.printHeapArray();
}