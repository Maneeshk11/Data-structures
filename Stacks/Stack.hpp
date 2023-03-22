#include "Stack.h"
#include <iostream>

// PUSH ELEMENT INTO STACK

template <typename T>
void Stack<T>::push(const T & data) {
    size++;
    StackNode* newNode = new StackNode(data);
    if (head_ == nullptr) {
        head_ = newNode;
        return;
    }
    newNode->next = head_;
    head_ = newNode;
    return;
}

// POP ELEMENT FROM TOP OF STACK

template <typename T>
void Stack<T>::pop() {
    if (head_ == nullptr) {
        std::cout << "ERR! Can't pop an empty stack." << std::endl;
        return;
    }
    size--;
    StackNode* thru = head_;
    head_ = thru->next;
    delete thru;
    thru = nullptr;
    return;
}

// RETURN THE TOP OF STACK

template <typename T>
const T & Stack<T>::top() {
    return head_->data;
}

// PRINT THE STACK FROM TOP TO BOTTOM

template <typename T>
void Stack<T>::printStack() {
    StackNode* thru = head_;
    while (thru != nullptr) {
        std::cout << thru->data << " ";
        thru = thru->next;
    }
    std::cout << std::endl;
    return;
}
