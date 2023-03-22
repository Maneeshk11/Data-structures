#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
    const string a = "apple";
    const string u = "banana";
    Stack<string> s;
    s.push(a);
    s.push(u);
    cout << s.size << endl;
    // s.pop();
    cout << s.top() << endl;
    s.printStack();
}