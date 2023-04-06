#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Implement the array.
class Stack {
private:
    int data[MAX_SIZE];
    int top;
public:
    Stack() {
        top = -1;
    }

    // Check whether Stack is full otherwise push elements in to the top of the stack.
    void push(int x) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        data[++top] = x;
    }
};

int main() {
    Stack s;

    s.push(4);
    s.push(8);
    s.push(12);
    s.push(16);

    return 0;
}
