
#pragma once 

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
    public:
        TreeNode* leftChild;
        TreeNode* rightChild;
        T data;
        TreeNode* parent;
        int sdist; // shortest path from a node to an external node
        TreeNode(T & data) : data(data), leftChild(nullptr), rightChild(nullptr), parent(nullptr), sdist(0) {}
};

template <typename T>
class LeftistTree {
    public:
        LeftistTree() : root_(nullptr) {}
        LeftistTree(vector<T>&array) : LeftistTree(){
            root_ = createLeftistTree(array);
            cout << "root value: " << root_->data << endl;
            if (root_->rightChild == nullptr) {
                cout << " yeahhh baby !" << endl;
            }
        }
        TreeNode<T>* createLeftistTree(vector<T>&array);
        TreeNode<T>* meldTrees(TreeNode<T>* & tree1, TreeNode<T>* & tree2);

    private:
        TreeNode<T>* root_;
};


#include "LeftistTree.hpp"