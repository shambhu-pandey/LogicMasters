# 📑 Queue and Stack Implementations in C++

This document contains **Queue** and **Stack** implementations in C++ using **arrays** and **linked lists**.  
Each section includes code, explanation, and usage.

---

## Table of Contents

1. [Queue using Array](#queue-using-array)  
2. [Queue using Linked List](#queue-using-linked-list)  
3. [Stack using Array](#stack-using-array)  
4. [Stack using Linked List](#stack-using-linked-list)  

---



## Stack using Array

```cpp
#include <iostream>
using namespace std;

class StackImpArray {
    int top;
    int capacity;
    int* st;

public:
    StackImpArray(int cap = 10) {
        capacity = cap;
        top = -1;
        st = new int[capacity];
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
        if (top == -1)
            cout << "Stack is empty!" << endl;
        else
            cout << "Top element: " << st[top] << endl;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << st[i] << " ";
        cout << endl;
    }

    ~StackImpArray() {
        delete[] st;
    }
};

int main() {
    int cap;
    cout << "Enter stack capacity: ";
    cin >> cap;

    StackImpArray s(cap);
    int choice, val;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
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
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}

```




## Queue using Array

```cpp
#include <iostream>
using namespace std;

class QueueImp {
    int start, end, cursize, capacity;
    int *q;
public:
    QueueImp(int cap = 10) {
        capacity = cap;
        q = new int[capacity];
        start = -1;
        end = -1;
        cursize = 0;
    }

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

    void pop() {
        if (cursize == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        int element = q[start];
        if (cursize == 1)
            start = end = -1;
        else
            start = (start + 1) % capacity;
        cursize--;
        cout << element << " removed from queue." << endl;
    }

    void front() {
        if (cursize == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element: " << q[start] << endl;
    }

    void getSize() {
        cout << "Current size: " << cursize << endl;
    }

    void display() {
        if (cursize == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements (front to rear): ";
        for (int i = 0; i < cursize; i++)
            cout << q[(start + i) % capacity] << " ";
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
        cout << "1. Push\n2. Pop\n3. Front element\n4. Display\n5. Size\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
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
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
```




## Stack using Linked List

```cpp
#include <iostream>
using namespace std;

class StackImpLinkedList {
    struct Node {
        int data;
        Node* link;
    };
    Node* top;

public:
    StackImpLinkedList() {
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
        if (!top) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        cout << top->data << " popped from stack." << endl;
        top = top->link;
        delete temp;
    }

    void peek() {
        if (!top)
            cout << "Stack is empty!" << endl;
        else
            cout << "Top element: " << top->data << endl;
    }

    void display() {
        if (!top) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }
};

int main() {
    StackImpLinkedList s;
    int choice, value;

    do {
        cout << "\n--- Stack Menu (Linked List) ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
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
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}

```




## Queue using Linked List

```cpp
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

        if (!front) {
            front = rear = newnode;
        } else {
            rear->next = newnode;
            rear = newnode;
        }
        cout << x << " enqueued successfully!" << endl;
    }

    void dequeue() {
        if (!front) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Dequeued element: " << front->data << endl;
        front = front->next;
        if (!front)
            rear = nullptr;
        delete temp;
    }

    void peek() {
        if (!front)
            cout << "Queue is empty!" << endl;
        else
            cout << "Front element: " << front->data << endl;
    }

    void display() {
        if (!front) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp) {
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
        cout << "\n--- Queue Menu (Linked List) ---\n";
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
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}

```





class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        stack<int> st;
        unordered_map<int , int>mp ;

        for(int i = n2-1 ; i>=0 ;i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }

            if(st.empty()){
                mp[nums2[i]]= -1;
            }
            else{
                mp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }
        int n1 = nums1.size();  
        vector<int> ans(n1);
        for(int i = 0 ; i<n1;i++){
            ans[i] = mp[nums1[i]];
        }

        return ans;
    }
};


maximum subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize maxSum with the first element of the array
        int maxsum = nums[0];
        int currsum = 0;

        for(int num : nums){
           // Either add current number to existing sum or start fresh with num
            currsum = max(num , currsum + num );
            // Update global maximum if currentSum is better
            maxsum = max(maxsum , currsum);
        }

        return maxsum;
    }
};