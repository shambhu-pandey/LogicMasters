# 🚀 Linked List Problem Set

Welcome to the **Linked List Problem Set**!
This collection contains common problems with solutions in **C++**.
Each problem includes **examples, explanation, solution, and complexity analysis**.

---

## 📑 Table of Contents

1. [🟢 Singly Linked List Creation](#1--singly-linked-list-creation)
2. [🔹 Insert at Head / Tail / Position](#2--insert-at-head--tail--position)
3. [🔴 Delete Node at Position](#3--delete-node-at-position)
4. [🟡 Doubly Linked List Operations](#4--doubly-linked-list-operations)
5. [🔵 Circular Linked List Operations](#5--circular-linked-list-operations)
6. [⚡ Pointer Basics](#6--pointer-basics)

---

# 1. 🟢 Singly Linked List Creation

**Difficulty:** 🟢 Easy
**Tags:** Linked List, Node, Pointer

### 💻 Solution (C++)

```cpp
struct Node{
    int data;
    Node* next;
    Node(int val): data(val), next(nullptr) {}
};

Node* arrayToLinkedList(int arr[], int size){
    if(size==0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;

    for(int i = 1; i<size; i++){
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

void printLinkedList(Node* head){
    Node* current = head;
    while(current != nullptr){
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr\n";
}
```

---

# 2. 🔹 Insert at Head / Tail / Position

**Difficulty:** 🟢 Easy
**Tags:** Linked List, Insertion

### 💻 Solution (C++)

```cpp
void insertAtHead(Node* &head, int val){
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int val){
    Node* temp = new Node(val);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int val){
    if(pos==1) { insertAtHead(head, val); return; }
    Node* temp = head;
    int count = 1;
    while(count < pos-1 && temp != nullptr){
        temp = temp->next;
        count++;
    }
    Node* nodeToInsert = new Node(val);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
    if(nodeToInsert->next == nullptr) tail = nodeToInsert;
}
```

---

# 3. 🔴 Delete Node at Position

**Difficulty:** 🟢 Easy
**Tags:** Linked List, Deletion

### 💻 Solution (C++)

```cpp
void deleteAtPosition(Node* &head, Node* &tail, int pos){
    if(pos==1){
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        if(head==nullptr) tail = nullptr;
        return;
    }
    Node* current = head;
    Node* previous = nullptr;
    int count = 1;
    while(count < pos && current != nullptr){
        previous = current;
        current = current->next;
        count++;
    }
    previous->next = current->next;
    if(current->next == nullptr) tail = previous;
    current->next = nullptr;
    delete current;
}
```

---

# 4. 🟡 Doubly Linked List Operations

**Difficulty:** 🟢 Easy
**Tags:** Doubly Linked List, Node, Insertion, Deletion

### 💻 Solution (C++)

```cpp
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node() {
        int value = this->data;
        cout << "The memory is free for node of data " << value << endl;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() { head = tail = NULL; }

    void insertAtHead(int d) {
        if (head == NULL) {
            Node* temp = new Node(d);
            head = temp;
            tail = temp;
        } else {
            Node* temp = new Node(d);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    void insertAtTail(int d) {
        if (tail == NULL) {
            Node* temp = new Node(d);
            head = temp;
            tail = temp;
        } else {
            Node* temp = new Node(d);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void insertAtPosition(int position, int d) {
        if (position == 1) {
            insertAtHead(d);
            return;
        }

        Node* temp = head;
        int cnt = 1;
        while (cnt < position - 1 && temp != NULL) {
            temp = temp->next;
            cnt++;
        }

        if (temp == NULL || temp->next == NULL) {
            insertAtTail(d);
            return;
        }

        Node* nodeToInsert = new Node(d);
        nodeToInsert->next = temp->next;
        temp->next->prev = nodeToInsert;
        temp->next = nodeToInsert;
        nodeToInsert->prev = temp;
    }

    void deleteNode(int position) {
        if (head == NULL) return;

        if (position == 1) {
            Node* temp = head;
            if (head->next != NULL) head->next->prev = NULL;
            head = temp->next;
            temp->next = NULL;
            delete temp;
        } else {
            Node* current = head;
            Node* previous = NULL;
            int cnt = 1;
            while (cnt < position && current != NULL) {
                previous = current;
                current = current->next;
                cnt++;
            }

            if (current == NULL) return;

            if (current->next != NULL) current->next->prev = previous;
            else tail = previous;

            previous->next = current->next;
            current->next = NULL;
            current->prev = NULL;
            delete current;
        }
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int getLength() {
        int len = 0;
        Node* temp = head;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }
};
```

---

# 5. 🔵 Circular Linked List Operations

**Difficulty:** 🟢 Medium
**Tags:** Circular Linked List, Node

### 💻 Solution (C++)

```cpp
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){ this->data = data; this->next = NULL; }
    ~Node(){ cout<<"Memory freed for node with data: "<<data<<endl; }
};

class CircularList{
    Node* head;
    Node* tail;
public:
    CircularList(){ head = tail = NULL; }

    void insertAtHead(int val){
        Node* newnode = new Node(val);
        if(head==NULL){
            head = tail = newnode;
            tail->next = head;
        } else {
            newnode->next = head;
            head = newnode;
            tail->next = head;
        }
    }

    void insertAtTail(int val){
        Node* newnode = new Node(val);
        if(head==NULL){
            head = tail = newnode;
            tail->next = head;
        } else {
            newnode->next = head;
            tail->next = newnode;
            tail = newnode;
        }
    }

    void insertAtPosition(int pos, int val){
        if(pos <= 0){
            cout<<"Invalid position"<<endl;
            return;
        }
        if(pos == 1){
            insertAtHead(val);
            return;
        }
        Node* newnode = new Node(val);
        Node* temp = head;
        int count = 1;
        while(count < pos-1 && temp->next != head){
            temp = temp->next;
            count++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        if(temp == tail) tail = newnode;
    }

    void deleteAtHead(){
        if(head == NULL) return;
        else if(head==tail){
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void deleteAtTail(){
        if(head==NULL) return;
        else if(head==tail){
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = tail;
            Node* prev = head;
            while(prev->next != tail) prev = prev->next;
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void deleteAtPosition(int pos){
        if(head == NULL) return;
        if(pos <= 0){
            cout<<"Invalid position"<<endl;
            return;
        }
        if(pos == 1){
            deleteAtHead();
            return;
        }
        Node* prev = head;
        int count = 1;
        while(count < pos-1 && prev->next != head){
            prev = prev->next;
            count++;
        }
        Node* curr = prev->next;
        if(curr == head){
            cout<<"Position out of range"<<endl;
            return;
        }
        prev->next = curr->next;
        if(curr == tail) tail = prev;
        curr->next = NULL;
        delete curr;
    }

    void print(){
        if(head==NULL){ cout<<"List is empty"<<endl; return; }
        cout<<head->data<<"->";
        Node* temp = head->next;
        while(temp != head){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<head->data<<" (back to head)"<<endl;
    }
};

```

---

# 6. ⚡ Pointer Basics

**Difficulty:** 🟢 Easy
**Tags:** Pointer, Address, Dereference

### ✅ Example

```cpp
int x = 10;
int* ptr = &x;
*ptr = 20;
cout << x; // Output: 20
```

---

**Lecture Slides:** [View Slides](https://drive.google.com/file/d/1yR9Rh5ptmFDw0kPL_mcNH6L34wUdorCE/view)
