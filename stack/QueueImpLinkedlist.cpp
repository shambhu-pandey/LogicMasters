#include <iostream>
using namespace std;

class QueueImpLinkedlist {
    struct Node {
        int data;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    QueueImpLinkedlist() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int x) {
        Node* newnode = new Node();
        newnode->data = x;
        newnode->next = nullptr;

        if (front == nullptr && rear == nullptr) {
            front = rear = newnode;
        } else {
            rear->next = newnode;
            rear = newnode;
        }
        cout << x << " enqueued successfully!" << endl;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Dequeued element: " << front->data << endl;
        front = front->next;
        if (front == nullptr) rear = nullptr; // if queue becomes empty
        delete temp;
    }

    void peek() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Front element: " << front->data << endl;
        }
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    QueueImpLinkedlist q;
    int choice, value;

    do {
        cout << "\n--- Queue Implementation (Linked List) ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                q.peek();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
