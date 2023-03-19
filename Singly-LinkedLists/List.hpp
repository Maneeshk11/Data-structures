#include "List.h"
#include <iostream>

template<typename T> 
const T & List<T>::operator[](unsigned index) {
    ListNode *thru = head_;
    while (index > 0 && thru->next!=nullptr) {
        thru = thru->next;
        index--;
    }
    return thru->data;
}

// ------------------ Insert element at the start of the list ---------------------

template <typename T>
void List<T>::insertAtFront(const T & data) {
    ListNode* newNode = new ListNode(data);
    newNode->next = head_;
    head_ = newNode;
}

// ---------------------- Insert element at the end of the list ---------------------

template <typename T>
void List<T>::insertAtBack(const T & data) {
    ListNode* newNode = new ListNode(data);
    ListNode* thru = head_;
    while (thru->next != nullptr) {
        thru = thru->next;
    }
    thru->next = newNode;
    return;
}

// ------------------------- Print the list --------------------------------

template <typename T>
void List<T>::printList() {
    ListNode* thru = head_;
    if (head_ == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    while (thru!=nullptr) {
        std::cout << thru->data << " ";
        thru = thru->next;
    }
    std::cout << std::endl;
}

// --------------------- remove the first element of the list --------------------------------

template <typename T>
void List<T>::removeFront() {
    if(head_ == nullptr) {
        return;
    }
    ListNode* thru = head_;
    head_ = thru->next;
    delete thru;
    thru = nullptr;
}

// ----------------------------  remove the last element of the list --------------------------------

template <typename T>
void List<T>::removeBack()  {
    if (head_ == nullptr)  {
        return;
    }
    ListNode* thru = head_;
    ListNode* prev = head_;
    while (thru->next != nullptr) {
        prev = thru;
        thru = thru->next;
    }
    if (thru == prev) {
        head_ = nullptr;
    }
    prev->next = nullptr;
    delete thru;
    thru = nullptr;
}

// ----------------------  Insert element at a specific index in the list ------------------------

template <typename T>
void List<T>::insertAtIndex(const T & data, unsigned index)  {
    ListNode* thru = head_;
    ListNode* newNode = new ListNode(data);
    if (index == 0) {
        if (head_ == nullptr) {
            head_ = newNode;
        }
        else {
            newNode->next = thru;
            head_ = newNode;
        }
        return;
    }
    if (head_ == nullptr) {
        if (index == 0) {
            head_ = newNode;
        }
        else {
            std::cout << "Can't insert. List size smaller than the specified index value." << std::endl;
        }
        return;
    }
    ListNode* prev = head_;
    while (index > 0 && thru->next != nullptr) {
        prev = thru;
        thru = thru->next;
        index--;
    }
    if (prev == thru && index == 1) {
        thru->next = newNode;
        return;
    }
    if (index > 0) {
        std::cout << "Can't insert. List size smaller than the specified index value." << std::endl;
        return;
    }
    newNode->next = thru;
    prev->next = newNode;
}

// --------------- Find a element in the list ----------------

template <typename T>
typename List<T>::ListNode *List<T>::find(const T & data) {
    if (head_ == nullptr)  {
        std::cout << data << " is not in the list." << std::endl;
        return nullptr;
    }
    int index=0;
    ListNode* thru = head_;
    while (thru != nullptr)  {
        if (thru->data == data) {
            std::cout << data << " is at index " << index << std::endl;
            return thru;
        }
        thru = thru->next;
        index++;
    }
    std::cout << data << " is not in the list." << std::endl;
    return nullptr;
}
