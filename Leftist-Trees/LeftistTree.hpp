#include <bits/stdc++.h>
#include "LeftistTree.h"

using namespace std;

template <typename T>
TreeNode<T>* LeftistTree<T>::createLeftistTree(vector<T>&array) {
    queue<TreeNode<T>*> initialqueue;
    for (int i=0; i<array.size(); i++) {
        TreeNode<T>* newnode = new TreeNode<T>(array[i]);
        initialqueue.push(newnode);
    } // we formed the initial queue with single element leftist trees

    while (initialqueue.size() > 1) {
        TreeNode<T>* tree1 = initialqueue.front();
        initialqueue.pop();
        TreeNode<T>* tree2 = initialqueue.front();
        initialqueue.pop();
        TreeNode<T>* meldedtree = meldTrees(tree1, tree2);
        initialqueue.push(meldedtree);
    }
    return initialqueue.front();
}

template <typename T>
TreeNode<T>* LeftistTree<T>::meldTrees(TreeNode<T>* & tree1, TreeNode<T>* & tree2) {
    stack<TreeNode<T>*> meldingStack; 
    meldingStack.push(tree1);
    meldingStack.push(tree2);
    while (meldingStack.size() > 1) {
        TreeNode<T>* lefttree = meldingStack.top();
        meldingStack.pop();
        TreeNode<T>* righttree = meldingStack.top();
        meldingStack.pop();
        if (isMin_ ? lefttree->data <= righttree->data : lefttree->data >= righttree->data) {
            if (lefttree->rightChild == nullptr) {
                if (lefttree->leftChild != nullptr && lefttree->leftChild->sdist >= righttree->sdist) {
                    lefttree->rightChild = righttree;
                    lefttree->sdist += righttree->sdist + 1;
                } else {
                    lefttree->rightChild = lefttree->leftChild;
                    lefttree->leftChild = righttree;
                    if (lefttree->rightChild != nullptr) {
                        lefttree->sdist = lefttree->rightChild->sdist;
                    }
                }
                righttree->parent = lefttree;
                meldingStack.push(lefttree);
            } else {
                TreeNode<T>* rightsubtree = lefttree->rightChild;
                rightsubtree->parent = nullptr;
                lefttree->rightChild = nullptr;
                meldingStack.push(lefttree);
                meldingStack.push(rightsubtree);
                meldingStack.push(righttree);
            }
        } else {
            if (righttree->rightChild == nullptr) {
                if (righttree->leftChild != nullptr && righttree->leftChild->sdist >= lefttree->sdist) {
                    righttree->rightChild = lefttree;
                    righttree->sdist += lefttree->sdist + 1;
                } else {
                    righttree->rightChild = righttree->leftChild;
                    righttree->leftChild = lefttree;
                    if (righttree->rightChild != nullptr) {
                        righttree->sdist = righttree->rightChild->sdist;
                    }
                }
                lefttree->parent = righttree;
                meldingStack.push(righttree);
            } else {
                TreeNode<T>* rightsubtree = righttree->rightChild;
                rightsubtree->parent = nullptr;
                righttree->rightChild = nullptr;
                meldingStack.push(righttree);
                meldingStack.push(rightsubtree);
                meldingStack.push(lefttree);
            }
        }
    } 
    return meldingStack.top();
}

template <typename T>
T & LeftistTree<T>::getRoot() {
    return root_->data;
}

template <typename T>
void LeftistTree<T>::put(T value) {
    TreeNode<T>* newnode = new TreeNode<T>(value);
    root_ = meldTrees(root_, newnode);
    return;
}

template <typename T>
void LeftistTree<T>::removeMin() {
    if (!isMin_) {
        throw runtime_error ("Cannot perform removeMin over a max-leftist tree");
    } else {
        TreeNode<T>* treeLeft = root_->leftChild;
        TreeNode<T>* treeRight = root_->rightChild;
        treeLeft->parent = nullptr;
        treeRight->parent = nullptr;
        root_ = meldTrees(treeLeft, treeRight);
    }
    return;
}

template <typename T>
void LeftistTree<T>::removeMax() {
    if (isMin_) {
        throw runtime_error("Cannot perform removeMax over a min-leftist tree");
    } else {
        root_->leftChild->parent = nullptr;
        root_->rightChild->parent = nullptr;
        TreeNode<T>* treeLeft = root_->leftChild;
        TreeNode<T>* treeRight = root_->rightChild;
        
        root_ = meldTrees(treeLeft, treeRight);
    }
    
    return;
}