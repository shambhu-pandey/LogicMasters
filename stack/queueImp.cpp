#include <iostream>
using namespace std;

class QueueImp {
    int start, end, cursize, capacity;
    int *q;

public:
    // constructor
    QueueImp(int cap = 10) {
        capacity = cap;
        q = new int[capacity];
        start = -1;
        end = -1;
        cursize = 0;
    }

    // insert element
    void push(int x) {
        if (cursize == capacity) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (cursize == 0) {
            start = 0;
            end = 0;
            q[end] = x;
        } else {
            end = (end + 1) % capacity;
            q[end] = x;
        }
        cursize++;
        cout << x << " inserted into queue." << endl;
    }

    // remove element
    void pop() {
        if (cursize == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        int element = q[start];
        if (cursize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % capacity;
        }
        cursize--;
        cout << element << " removed from queue." << endl;
    }

    // front element
    void front() {
        if (cursize == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element: " << q[start] << endl;
    }

    // size of queue
    void getSize() {
        cout << "Current size: " << cursize << endl;
    }

    // display elements
    void display() {
        if (cursize == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements (front to rear): ";
        for (int i = 0; i < cursize; i++) {
            cout << q[(start + i) % capacity] << " ";
        }
        cout << endl;
    }

    ~QueueImp() {
        delete[] q;
    }
};

int main() {
    int cap;
    cout << "Enter queue capacity: ";
    cin >> cap;

    QueueImp q(cap);

    int choice, val;
    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Push (Enqueue)\n";
        cout << "2. Pop (Dequeue)\n";
        cout << "3. Front element\n";
        cout << "4. Display\n";
        cout << "5. Size\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                q.push(val);
                break;
            case 2:
                q.pop();
                break;
            case 3:
                q.front();
                break;
            case 4:
                q.display();
                break;
            case 5:
                q.getSize();
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
