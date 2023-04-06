#include <iostream>

using namespace std;

// Represent the index of the top element in the stack.

class Stack {
private:
    int *arr;   // Pointer to array
    int top;    // Index of top element
    int size;   // Maximum size of array

public:
    Stack(int s) {
        size = s;
        arr = new int[size];    // Allocate memory for array
        top = -1;               // Set top index to -1
    }

    ~Stack() {
        delete[] arr;           // Free memory allocated for array
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Error: Stack is full." << endl;
            return;
        }
        arr[++top] = x;         // increment top index and insert element
    }
    
    //Remove top element of the static array.
    
    int pop() {
        if (isEmpty()) {
            cout << "Error: Stack is empty." << endl;
            return -1;
        }
        return arr[top--];      // Return top element and decrement top index
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter size of stack: ";
    cin >> size;
    Stack s(size);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.print();

    int popped = s.pop();
    cout << "Popped element: " << popped << endl;
    s.print();

    return 0;
}
