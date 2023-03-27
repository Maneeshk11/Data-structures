

#include <iostream>
#include <vector>
#include "Tree.h"
#include <queue>

template <typename T>
void BinaryTree<T>::createBinaryTree(std::vector<T>&data) {
    if (data.size() == 0) {
        return;
    }
    std::queue<TreeNode**> ptrptr;
    root_ = new TreeNode(data[0]);
    ptrptr.push(&(root_->left));
    ptrptr.push(&(root_->right));
    for (int i=1;i<data.size();i++) {
        TreeNode** actualPtr = ptrptr.front();
        TreeNode*& newNode = *actualPtr;
        newNode = new TreeNode(data[i]);
        ptrptr.pop();
        ptrptr.push(&(newNode->left));
        ptrptr.push(&(newNode->right));
    }
    return;
}

// -------------------------------------- INORDER TRAVERSAL --------------------------------------

template<typename T>
void BinaryTree<T>::inOrder() {
    inOrderD(root_);
    std::cout << std::endl;
    return;
}

template<typename T>
void BinaryTree<T>::inOrderD(BinaryTree<T>::TreeNode* node) {
    if (node != nullptr) {
        inOrderD(node->left);
        std::cout << node->data << " ";
        inOrderD(node->right);
    }
}

// ------------------------------------------ PREORDER TRAVERSAL -------------------------------------

template<typename T>
void BinaryTree<T>::preOrder() {
    preOrderD(root_);
    std::cout << std::endl;
    return;
}

template<typename T>
void BinaryTree<T>::preOrderD(BinaryTree<T>::TreeNode* node) {
    if (node != nullptr) {
        std::cout << node->data << " ";
        preOrderD(node->left);
        preOrderD(node->right);
    }
}

// ----------------------------------------POSTORDER TRAVERSAL ---------------------------------------- 

template<typename T>
void BinaryTree<T>::postOrder() {
    postOrderD(root_);
    std::cout << std::endl;
    return;
}

template<typename T>
void BinaryTree<T>::postOrderD(BinaryTree<T>::TreeNode* node) {
    if (node != nullptr) {
        postOrderD(node->left);
        postOrderD(node->right);
        std::cout << node->data << " ";
    }
}

// --------------------------------------- DESTROY SUBTREE --------------------------------------------

template<typename T>
void BinaryTree<T>::destroySubTree(TreeNode* node) {
    if (!node) {
        return;
    }
    destroySubTree(node->left);
    destroySubTree(node->right);

    node->left = nullptr;
    node->right = nullptr;

    delete node;
}


// ------------------------------------ Destroy whole tree -------------------------------------

template<typename T>
void BinaryTree<T>::destroyWholeTree() {
    destroySubTree(root_);
    root_ = nullptr;
}