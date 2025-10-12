#include <iostream>
using namespace std;

class StackImpLinkedlist {
    struct Node {
        int data;
        Node* link;
    };

    Node* top;  // pointer to top of stack

public:
    StackImpLinkedlist() {
        top = nullptr;
    }

    void push(int x) {
        Node* newnode = new Node();
        newnode->data = x;
        newnode->link = top;
        top = newnode;
        cout << x << " pushed into stack." << endl;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        cout << temp->data << " popped from stack." << endl;
        top = top->link;
        delete temp;
    }

    void peek() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Top element: " << top->data << endl;
        }
    }

    void display() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }
};

int main() {
    StackImpLinkedlist s;
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
