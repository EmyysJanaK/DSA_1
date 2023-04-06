#include <iostream>
using namespace std;

// Implement the class.
class Stack {
private:
    int top;
    int* arr;
    int size;

public:
    Stack(int s) {
        top = -1;
        size = s;
        arr = new int[size];
    }

    void push(int value) {
        if (top == size - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
        cout << "Pushed Element: " << arr[top] << endl;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter size of stack: "; // Implementing a static array.
    cin >> size;

    Stack s(size);

    int choice, value;
    while (1) {
        cout << "1. Push\n2. Display ";
        cin >> choice;
        // Input the element just entered to be pushed.
        switch (choice) {
        case 1:
            cout << "Enter value to be pushed: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.display();
            break;
        // Display whether invalid input.
        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
