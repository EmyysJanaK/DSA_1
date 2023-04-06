#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int data[MAX_SIZE];
    int top;
public:
    Stack() {
        top = -1;
    }

    
    // Check whether there can be removed elemnts from the top of the stack.
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
    // Show the head value of the stack.
    int topValue() {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return data[top];
    }

    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    Stack s;

    s.pop();
    s.pop();
    s.pop();
    s.pop(); // output: Stack Underflow
    return 0;
}
