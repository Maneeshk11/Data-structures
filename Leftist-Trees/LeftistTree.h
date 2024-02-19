
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
        LeftistTree(vector<T>&array, bool isMin) : LeftistTree(){ 
            isMin_ = isMin;
            root_ = createLeftistTree(array);
        } 
        TreeNode<T>* createLeftistTree(vector<T>&array);
        TreeNode<T>* meldTrees(TreeNode<T>* & tree1, TreeNode<T>* & tree2);
        T & getRoot();
        
        bool isMin_;
    private:
        TreeNode<T>* root_;
};


#include "LeftistTree.hpp"