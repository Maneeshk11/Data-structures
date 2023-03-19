
#pragma once

template <typename T> 

class List {
    public:
        const T & operator[](unsigned index);
        void insertAtFront(const T & data);
        void insertAtBack(const T & data);
        void printList();
        void removeFront();
        void removeBack();
        void insertAtIndex(const T & data, unsigned index);
        List() : head_(nullptr) {}

    private:
        class ListNode {
            public:
                ListNode* next;
                const T & data;
                ListNode(const T & data) : data(data), next(nullptr) { }
        };
        ListNode* head_;
        ListNode* find(const T & data);
};

#include "List.hpp"