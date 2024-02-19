#include <bits/stdc++.h>
#include "LeftistTree.h"

using namespace std;

int main() {
    vector<int> arr = {7, 1, 9, 11, 2};
    LeftistTree<int> ourtree(arr, false);
    cout << ourtree.getRoot() << endl;
}