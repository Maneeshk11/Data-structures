#include <iostream>
#include "Tree.h"
#include <vector>
using namespace std;

 
int main() {
    vector<int> arr = {1, 2, 3, 4 , 5, 6, 7};
    BinaryTree<int> tree(arr);
    tree.preOrder();
    tree.inOrder();
    tree.postOrder();
    tree.destroyWholeTree(); 
}