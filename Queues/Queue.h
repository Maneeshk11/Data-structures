#pragma once

template <typename T>
class Queue {
    public:
        Queue(): head_(nullptr) {}
        int size();
        void push(const T & data);
        
    private:
        class QueueNode {
            public:
                QueueNode* next;
                const T & data;
                QueueNode(const T & data) : data(data), next(nullptr) {}
        };
        QueueNode* head_;
};