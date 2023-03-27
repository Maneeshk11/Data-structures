#pragma once 

#include <iostream>
#include <vector>


template<typename T>
class BinaryTree {
    public:
        BinaryTree() : root_(nullptr) {}
        void createBinaryTree(std::vector<T> & data);
        BinaryTree(std::vector<T> & data) : BinaryTree() {
            createBinaryTree(data);
        }
        class TreeNode {
            public:
                TreeNode* left;
                TreeNode* right;
                T & data;
                TreeNode(T & data) : data(data), left(nullptr), right(nullptr) {}
        };
        void inOrder();
        void preOrder();
        void postOrder();
        void inOrderD(TreeNode* node);
        void preOrderD(TreeNode* node);
        void postOrderD(TreeNode* node);
        void destroySubTree(TreeNode* node);
        void destroyWholeTree();
    private:
        TreeNode* root_;

};

#include "Tree.hpp"