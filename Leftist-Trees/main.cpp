#include <bits/stdc++.h>
#include "LeftistTree.h"

using namespace std;

int main() {
    vector<int> arr = {7, 1, 9, 11, 2};
    LeftistTree<int> ourtree(arr, false);
    cout << ourtree.getRoot() << endl;
    int value = 19;
    ourtree.put(value);
    cout << ourtree.getRoot() << endl;
    ourtree.put(23);
    cout << ourtree.getRoot() << endl;

    ourtree.removeMax();
    cout << ourtree.getRoot() << endl;
}