#include <iostream>
#include "List.h"

int main() {
    List<int> list;
    const int a = 8;
    const int b = 9;
    const int c = 10;
    const int d = 11;
    const int e = 12;
    const int f = 13;
    list.printList();
    list.insertAtBack(a);
    list.insertAtBack(b);
    list.insertAtBack(c);
    list.insertAtBack(d);
    list.insertAtBack(e);
    list.insertAtBack(f);
    list.printList();
    std::cout << list.size << std::endl;
    list.reverseList();
    // list.removeAtFront();
    list.printList();
    std::cout << list.size << std::endl;
}