
#include "List.h"
#include <iostream>

template <typename T>
const T &  List<T>::operator[](unsigned index) {
    ListNode* thru = head_;
    while (index > 0 && thru->next != nullptr) {
        thru = thru->next;
        index--;
    }
    return thru->data;
}

// INSERT ELEMENT AT FRONT OF THE LIST

template <typename T>
void List<T>::insertAtFront(const T & data) {
    size++;
    ListNode* newNode = new ListNode(data);
    ListNode* thru = head_;
    if (head_ == nullptr && tail_ == nullptr) {
        head_ = newNode;
        tail_ = newNode;
        return;
    }
    newNode->next = thru;
    // newNode->prev = nullptr;
    thru->prev = newNode;
    head_ = newNode;
    return;
}


// INSERT ELEMENT AT BACK OF THE LIST

template <typename T>
void List<T>::insertAtBack(const T & data) {
    size++;
    ListNode* newNode = new ListNode(data);
    if (head_ == nullptr && tail_ == nullptr) {
        head_ = newNode;
        tail_ = newNode;
        return;
    }
    ListNode* thru = tail_;
    thru->next = newNode;
    newNode->prev = thru;
    tail_ = newNode;
    return;
}

// DELETE ELEMENT FROM THE FRONT OF THE LIST
template <typename T>
void List<T>::removeAtFront() {
    if (head_ == nullptr && tail_ == nullptr) {
        std::cout << "ERR!, Cant remove from emplty list" << std::endl;
        return;
    }
    size--;
    if (head_ == tail_) {
        ListNode* thru = head_;
        head_ = nullptr;
        tail_ = nullptr;
        delete thru;
        thru = nullptr;
        return;
    }
    ListNode* thru = head_;
    ListNode* futHead = thru->next;
    head_ = thru->next;
    futHead->prev = nullptr;
    delete thru;
    thru = nullptr;
    return;
}


// DELETE ELEMENT FROM BACK OF THE LIST

template <typename T>
void List<T>::removeAtBack() {
    if(head_ == nullptr && tail_ == nullptr) {
        std::cout << "ERR! Can't remove from an empty list" << std::endl;
        return;
    }
    size--;
    if (head_ == tail_)  {
        ListNode* thru = head_;
        head_ = nullptr;
        tail_ = nullptr;
        delete thru;
        thru = nullptr;
        return;
    }
    ListNode* thru = tail_;
    ListNode* futTail = thru->prev;
    tail_ = thru->prev;
    futTail->next = nullptr;
    delete thru;
    thru = nullptr;
    return;
}

// PRINT THE LIST

template <typename T>
void List<T>::printList() {
    ListNode* thru = head_;
    if (head_ == nullptr)  {
        std::cout << "ERR! No elements in the list to print" << std::endl;
        return;
    }
    while (thru != nullptr)  {
        std::cout << thru->data << " ";
        thru = thru->next;
    }
    std::cout << std::endl;
    return;
}

// REVERSE THE LIST

template <typename T>
void List<T>::reverseList() {
    if (head_ == tail_) {
        if (head_ == nullptr) {
            std::cout << "ERR! Can't reverse an empty list" << std::endl;
        } 
        return;
    }
    ListNode* finalTail = head_;
    ListNode* thru = head_;
    ListNode* dummy = head_;
    while (thru->next != nullptr) {
        ListNode* fut = thru->next;
        thru->next = thru->prev;
        thru->prev = fut;
        dummy = thru;
        thru = fut;
    }
    thru->next = dummy;
    thru->prev = nullptr;
    head_ = thru;
    tail_ = finalTail;
    return;
}