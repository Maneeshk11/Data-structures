
#pragma once

template <typename T>
class Stack {
    public:
        Stack() : head_(nullptr) {}
        void push(const T & data);
        void pop();
        const T & top();
        void printStack();
        int size = 0;
    private:
        class StackNode {
            public:
                StackNode* next;
                const T & data;
                StackNode(const T & data) : data(data), next(nullptr) {}
        };
        StackNode* head_;
};

#include "Stack.hpp"