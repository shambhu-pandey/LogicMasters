#include<iostream>   // your comment
using namespace std;

// Node class definition
class Node {
public:
    int data;   // stores the data
    Node* next; // pointer to the next node

    // constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // destructor (called when node is deleted)
    ~Node() {
        cout << "memory is free for node with data " << this->data << endl;
    }
};

// Function to insert a node at the beginning (head) of the list
void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);   // create new node
    temp->next = head;          // point new node to current head
    head = temp;                // update head
}

// Function to insert a node at the end (tail) of the list
void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);   // create new node
    tail->next = temp;          // link old tail to new node
    tail = temp;                // update tail
}

// Function to insert node at a specific position
void insertAtPosition(Node* &tail, Node* &head, int position, int d) {
    // case 1: insert at start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    // traverse till one node before the desired position
    while(cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    // if position is invalid (greater than length+1)
    if(temp == NULL) return;

    // case 2: insert at end
    if(temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    // case 3: insert in between
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

    // update tail if inserted at last position
    if(nodeToInsert->next == NULL) {
        tail = nodeToInsert;
    }
}

// Function to delete node at a given position
void deleteNode(int position, Node* &head, Node* &tail) {
    // case 1: delete first node
    if(position == 1) {
        Node* temp = head;
        head = head->next;   // move head to next node
        temp->next = NULL;   // unlink node
        delete temp;         // free memory
        if(head == NULL) tail = NULL; // if list becomes empty
    }
    // case 2: delete any other node
    else {
        Node* current = head;
        Node* previous = NULL;
        int cnt = 1;

        // traverse till the node to be deleted
        while(cnt < position && current != NULL) {
            previous = current;
            current = current->next;
            cnt++;
        }

        if(current == NULL) return; // invalid position

        previous->next = current->next;  // unlink node

        // update tail if last node is deleted
        if(current->next == NULL) {
            tail = previous;
        }

        current->next = NULL; // unlink completely
        delete current;       // free memory
    }
}

// Function to print the linked list
void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function
int main() {
    Node* node1 = new Node(10);  // create first node

    Node* head = node1; // head pointer points to first node
    Node* tail = node1; // tail pointer also points to first node

    print(head);  // print current list

    insertAtHead(head, 12);  // insert at head
    print(head);

    insertAtHead(head, 15);  // insert at head again
    print(head);

    insertAtTail(tail, 8);   // insert at tail
    print(head);

    insertAtPosition(tail, head, 3, 100); // insert at position 3
    print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    deleteNode(5, head, tail);   // delete node at position 5
    print(head);

    cout << "Head: " << (head ? head->data : -1) << endl;
    cout << "Tail: " << (tail ? tail->data : -1) << endl;

    return 0;
}
