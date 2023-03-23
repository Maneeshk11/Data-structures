
#include "Queue.h"
#include <iostream>

// PUSH AN ELEMENT INTO THE QUEUE

template<typename T>
void Queue<T>::push(const T & data) {
    QueueNode* newNode = new QueueNode(data);
    size_++;
    if (head_ == nullptr && tail_ == nullptr) {
        head_ = newNode;
        tail_ = newNode;
        return;
    }
    QueueNode* thru = head_;
    newNode->next = head_;
    thru->prev = newNode;
    head_ = newNode;
    return;
}

// POP ELEMENT FROM THE QUEUE

template<typename T>
void Queue<T>::pop() {
    if (head_ == nullptr && tail_ == nullptr) {
        std::cout << "ERR! Can't pop from an empty queue" << std::endl;
        return;
    }
    size_--;
    if (head_ == tail_) {
        QueueNode* thru = head_;
        head_ = nullptr;
        tail_ = nullptr;
        delete thru;
        thru = nullptr;
        return;
    }
    QueueNode* thru = tail_;
    QueueNode* nextFinal = thru->prev;
    tail_ = nextFinal;
    nextFinal->next = nullptr;
    delete thru;
    thru = nullptr;
    return;
}

// PRINT THE QUEUE

template<typename T>
void Queue<T>::printQueue() {
    QueueNode* thru = head_;
    while (thru != nullptr) {
        std::cout << thru->data << " " ;
        thru = thru->next;
    }
    std::cout << std::endl;
    return;
}

// RETURN SIZE OF THE QUEUE

template<typename T>
int Queue<T>::size() {
    return size_;
}

// RETURN THE FRONT ELEMENT OF QUEUE

template<typename T>
const T & Queue<T>::front() {
    return tail_->data;
}