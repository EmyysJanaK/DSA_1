#include <iostream>
using namespace std;

// Class to initiate the linked list.
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};
// Implement the Stack.
class Stack {
public:
    Node* top;
    int size;

    Stack() {
        top = NULL;
        size = 0;
    }
    // Adding random elements to the stack.
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        size++;
    }
    // Remove the top elements.
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    void display() {
        Node* current = top;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int n;

    cout << "Enter the number of elements to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        s.push(data);
    }

    cout << "Stack before pop: ";
    s.display();
    
    // Pop 3 times.
    s.pop();
    s.pop();
    s.pop();

    cout << "Stack after pop: ";
    s.display();

    return 0;
}
