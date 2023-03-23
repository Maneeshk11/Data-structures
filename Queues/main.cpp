#include "Queue.h"
#include <iostream>

int main() {
    const int a = 100;
    const int b = 200;
    const int c = 300;
    const int d = 400;

    Queue<int> q;
    q.push(a);
    q.push(b);
    q.push(c);
    std::cout << q.size() <<std::endl;
    q.printQueue();
    q.pop();
    q.printQueue();
    q.push(d);
    q.printQueue();
    std::cout << q.front() <<std::endl;
}