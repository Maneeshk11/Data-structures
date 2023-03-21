
#pragma once 

template <typename T>

class List {
    public:
        const T & operator[](unsigned index);
        void insertAtFront(const T & data);
        void insertAtBack(const T & data);
        void removeAtFront();
        void removeAtBack();
        void printList(); // only for primitive data types containing lists
        void reverseList();
        List() : head_(nullptr), tail_(nullptr) {};
        int size = 0;

    private:
        class ListNode {
            public:
                ListNode* next;
                ListNode* prev;
                const T & data;
                ListNode(const T & data) : data(data), next(nullptr), prev(nullptr) {}
                ListNode() : data(0), next(nullptr), prev(nullptr) {}
        };
        ListNode* head_;
        ListNode* tail_;
};

#include "List.hpp"