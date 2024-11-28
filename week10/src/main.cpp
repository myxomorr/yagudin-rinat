#include <iostream>
#include "../include/Stack.hpp"

using namespace std;

int main() {
    Stack<int> stack1;

    stack1.push(10);
    stack1.push(20);
    stack1.push(30);

    cout << "Top element: " << stack1.top() << endl;
    cout << "Stack size: " << stack1.size() << endl;

    cout << "Popped element: " << stack1.pop() << endl;
    cout << "Popped element: " << stack1.pop() << endl;
    cout << "Stack size after pops: " << stack1.size() << endl;

    return 0;
}
