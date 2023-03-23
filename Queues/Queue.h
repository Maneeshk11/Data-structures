#pragma once

template <typename T>
class Queue {
    public:
        Queue(): head_(nullptr), tail_(nullptr) {}
        int size();
        void push(const T & data);
        void pop();
        void printQueue();
        const T & front();
        
    private:
        class QueueNode {
            public:
                QueueNode* next;
                QueueNode* prev;
                const T & data;
                QueueNode(const T & data) : data(data), next(nullptr), prev(nullptr) {}
        };
        QueueNode* head_;
        QueueNode* tail_;
        int size_ = 0;
};

#include "Queue.hpp"