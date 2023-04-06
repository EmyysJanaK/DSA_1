#include <iostream>

using namespace std;

// Define the linked list node structure
struct Node {
    int data;
    Node* next;
};

// Define the stack class
class Stack {
    private:
        Node* top;

    public:
        Stack() {
            top = NULL;
        }

        void push(int value) {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = top;
            top = newNode;
        }

        void display() {
            if (top == NULL) {
                cout << "Stack is empty" << endl;
                return;
            }

            // Create an array to store the stack contents
            int size = 0;
            Node* temp = top;
            while (temp != NULL) {
                size++;
                temp = temp->next;
            }

            int* stackArray = new int[size];
            temp = top;
            for (int i = 0; i < size; i++) {
                stackArray[i] = temp->data;
                temp = temp->next;
            }

            // Display the stack contents in array format
            cout << "Stack contents: [";
            for (int i = size - 1; i >= 0; i--) {
                cout << stackArray[i];
                if (i > 0) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }
};

int main() {
    // Input the length of the list.
    int size;
    cout << "Enter the size of the linked list: ";
    cin >> size;

    // Pushing the random elements in to the linked list.
    Stack stack;
    int value;
    for (int i = 0; i < size; i++) {
        cout << "Enter a value to push onto the stack: ";
        cin >> value;
        stack.push(value);
    }

    stack.display();

    return 0;
}
