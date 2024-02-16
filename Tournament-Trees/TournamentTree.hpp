#include "TournamentTree.h"
#include <bits/stdc++.h>

using namespace std;

template <typename T>
void TournamentTree<T>::createTournamentTree(vector<T>&array, TreeNode* & root_, bool isMin_, bool isLoser) {
    // Initialized the players
    queue<TreeNode*> draftQueue;
    for (int i=0; i<array.size(); i++) {
        TreeNode* tnode = new TreeNode(array[i]);
        draftQueue.push(tnode);
    }

    //playing matches
    int roundPlayers = draftQueue.size();
    while (roundPlayers > 1) {
        queue<TreeNode*> levelqueue;
        while (!draftQueue.empty()) {
            if (draftQueue.size() == 1) {
                levelqueue.push(draftQueue.front());
                draftQueue.pop();
                break;
            }
            TreeNode* left = draftQueue.front();
            draftQueue.pop();
            TreeNode* right = draftQueue.front();
            draftQueue.pop();
            TreeNode* parent;
            if (isLoser) {
                T temp = isMin_ ? max(left->winnerCandidate, right->winnerCandidate) : min(left->winnerCandidate, right->winnerCandidate); 
                T winnerTemp =  isMin_ ? min(left->winnerCandidate, right->winnerCandidate) : max(left->winnerCandidate, right->winnerCandidate); 
                parent = new TreeNode(temp, winnerTemp);
            } else {
                T temp = isMin_ ? min(left->data, right->data) : max(left->data, right->data);
                parent = new TreeNode(temp);
            }
            parent->rightChild = right;
            parent->leftChild = left;
            right->parent = parent;
            left->parent = parent;
            levelqueue.push(parent);
        }
        roundPlayers = levelqueue.size();
        draftQueue = levelqueue;
    }

    // store root pointer
    root_ = draftQueue.front();
}


// --------------------------------  winner tree methods -----------------------------------

template <typename T>
T & TournamentTree<T>::WinnerTree::getWinner() {
    if (root_ == nullptr) {
        return root_->data;
    }
    return root_->data;
}

template <typename T>
void TournamentTree<T>::WinnerTree::replaceWinnerAndReplay(T newElement) {
    TreeNode* temp = root_;
    while (temp->leftChild != nullptr && temp->rightChild != nullptr) {
        if (temp->data == temp->leftChild->data) {
            temp = temp->leftChild;
        } else {
            temp = temp->rightChild;
        }
    }
    temp->data = newElement;
    if (temp == root_) {
        return;
    }
    TreeNode* winner = temp->parent;
    while (true) {
        T minval = isMin_ ? min(winner->leftChild->data, winner->rightChild->data) : max(winner->leftChild->data, winner->rightChild->data);
        winner->data = minval;
        if (winner == root_) {
            break;
        }
        winner = winner->parent;
    }  
    
}


// --------------------------------  loser tree methods -----------------------------------

template <typename T>
T & TournamentTree<T>::LoserTree::getWinner() {
    if (root_ == nullptr) {
        return root_->winnerCandidate;
    }
    return root_->winnerCandidate;
    
}

template <typename T>
void TournamentTree<T>::LoserTree::replaceWinnerAndReplay(T newElement) {
    TreeNode* temp = root_;
    while (temp->leftChild != nullptr && temp->rightChild != nullptr) {
        if (temp->winnerCandidate == temp->leftChild->winnerCandidate) {
            temp = temp->leftChild;
        } else {
            temp = temp->rightChild;
        }
    }
    temp->data = newElement;
    temp->winnerCandidate = newElement;
    if (temp == root_) {
        return;
    }
    TreeNode* winner = temp->parent;
    
    while (true) {
        T loserval = isMin_ ? max(winner->leftChild->winnerCandidate, winner->rightChild->winnerCandidate) : min(winner->leftChild->winnerCandidate, winner->rightChild->winnerCandidate);
        T winnerTemp =  isMin_ ? min(winner->leftChild->winnerCandidate, winner->rightChild->winnerCandidate) : max(winner->leftChild->winnerCandidate, winner->rightChild->winnerCandidate);
        winner->data = loserval;
        winner->winnerCandidate = winnerTemp;
        if (winner == root_) {
            break;
        }
        winner = winner->parent;
    }  
    
}