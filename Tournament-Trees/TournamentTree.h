#pragma once 

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TournamentTree {
    public:
        class TreeNode {
            public:
                TreeNode* leftChild;
                TreeNode* rightChild;
                T data;
                T winnerCandidate;
                TreeNode* parent;
                TreeNode(T & data) : data(data), winnerCandidate(data), leftChild(nullptr), rightChild(nullptr), parent(nullptr) {}
                TreeNode(T & data, T & winnerCandidate) : data(data), winnerCandidate(winnerCandidate), leftChild(nullptr), rightChild(nullptr), parent(nullptr) {}
        };

        class WinnerTree {
            public:
                bool isMin_;
                WinnerTree() : root_(nullptr), isMin_(true) {}
                WinnerTree(vector<T>&array, bool order) : WinnerTree(){
                    isMin_ = order;
                    createTournamentTree(array, root_, isMin_, false);
                }
                WinnerTree(TreeNode* & other) : WinnerTree() {
                    root_ = cloneTree(other);
                }
                T & getWinner();
                void replaceWinnerAndReplay(T newElement);
                TreeNode* cloneTree(TreeNode* TreeNode);
                vector<int> generateSortedArray();
            private:
                TreeNode* root_;
        };

        class LoserTree {
            public:
                bool isMin_;
                LoserTree() : root_(nullptr), isMin_(true) {}
                LoserTree(vector<T>&array, bool order) : LoserTree(){
                    isMin_ = order;
                    createTournamentTree(array, root_, isMin_, true);
                }
                T & getWinner();
                void replaceWinnerAndReplay(T newElement);
            private:
                TreeNode* root_;
        };

        static void createTournamentTree(vector<T>&array, TreeNode* & root_, bool isMin_, bool isLoser);
};

#include "TournamentTree.hpp"