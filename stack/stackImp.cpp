#include <iostream>
using namespace std;

class stackImp {
    int top;
    int capacity;
    int st[100];  // fixed size stack for simplicity

public:
     // constructor
    stackImp(int cap = 10) {
        capacity = cap;
        top = -1;
    }

    void push(int x) {
        if (top >= capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        st[++top] = x;
        cout << x << " pushed into stack." << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << st[top--] << " popped from stack." << endl;
    }

    void peek() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return;
        }
        cout << "Top element: " << st[top] << endl;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << st[i] << " ";
        }
        cout << endl;
    }

    // destructor
    ~stackImp() {
        delete[] st;
    }
};

int main() {
    int cap;
    cout << "Enter capacity of stack: ";
    cin >> cap;

    stackImp s(cap);

    int choice, val;
    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                s.push(val);
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
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
