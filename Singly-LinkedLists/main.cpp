#include "List.h"
#include <iostream>

int main() {
    List<int> list;
    const int a = 30;
    const int b = 20;
    const int c = 234;
    const int d = 345;
    list.insertAtFront(a);
    list.insertAtFront(b);
    list.insertAtFront(c);
    list.insertAtFront(d);
    list.printList();
    const int e = 69;
    list.insertAtIndex(e, 2);
    list.printList();
    // List<int>::ListNode* elem = list.find(20);
}   