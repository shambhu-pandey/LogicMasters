// #include<iostream>
// using namespace std;

// class Node{

//     public:
//     int data;
//     Node* next;

//     //constructor
//     Node(int data){
//         this->data = data;
//         this->next = NULL;
//     }

//     ~Node(){
//         int value = this->data;
//         // sirf current node free hoga
//         cout<<"memory is free for node with data "<<value<<endl;
//     }
// };

// void insertAtHead(Node* &tail , Node* &head, int d){
//   if(head == NULL){
//    Node* temp = new Node(d);
//    head = temp;
//    tail = temp;
//   }
//   else{
//       //new node create
//     Node* temp= new Node(d);
//     temp ->next= head;
//     head= temp;
//   }
// }

// void insertAtTail(Node* & tail, Node* &head, int d){
//    if(tail==NULL){
//      Node* temp = new Node(d);
//      head = temp;
//      tail =  temp;
//    }
//    else{
//      //create new node
//     Node* temp = new Node(d);
//     tail->next = temp;
//     tail=temp;
//    }
// }

// void insertAtPosition(Node* & tail , Node* &head ,int position , int d ){

//     //insert at start
//     if(position==1){
//         insertAtHead(tail , head, d);
//         return;
//     }

//     Node* temp = head;
//     int cnt=1;  
    
//     // jis position par insert karna hai wha se ek kam  par temp ko le ja rhe hai
//     while(cnt<position-1 && temp!=NULL){
//         temp = temp->next;
//         cnt++;
//     }

//     if(temp==NULL) return; 

//     if(temp->next==NULL){
//         insertAtTail(tail,head , d);
//         return;
//     }

//     //create new node
//     Node* nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next;
//     temp->next  =   nodeToInsert;
// }


// void deleteNode(int position ,Node* & head, Node* & tail){
//     if(position==1){
//         Node* temp = head;
//         head = head->next;
//         if(head==NULL) tail=NULL;  // agar list empty ho gayi
//         temp->next = NULL;
//         delete(temp);

//     }
//     else{
//         Node* current = head;
//         Node* previous = NULL;
//         int cnt=1;
//         while(cnt<position && current!=NULL){
//             previous = current;
//             current=current->next;
//             cnt++;
//         }

//         if(current==NULL) return; // position out of range

//         previous->next = current->next;
//         if(current->next==NULL){ 
//             // agar last node delete kar rhe h to tail update karo
//             tail = previous;
//         }
//         current->next = NULL;
//         delete(current);
//     }
// }

// void print(Node* &head){
//     Node* temp =head;

//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }
//     cout<<endl;
// }


// int main(){
//     // Node* node1 = new Node(10);  // new node ye banane ke baad constructor call hoga 

//     // Node* head = node1;
//     // Node* tail= node1;


//     Node* head = NULL;
//     Node* tail = NULL;

//     print(head);

//     insertAtHead(tail , head ,12);
//     print(head);
   
//     insertAtHead(tail ,head , 15);
//     print(head);

//     insertAtTail(tail,head ,8);
//     print(head);

//     insertAtPosition(tail ,head , 3 , 100);
//     print(head);
     
//     cout<<"head "<<head->data<<endl;
//     cout<<"tail "<<tail->data<<endl;

//     deleteNode(4,head,tail);  // ab tail bhi update hoga
//     print(head);

//       cout<<"head "<<head->data<<endl;
//     cout<<"tail "<<tail->data<<endl;
    

//     return 0;
// }




#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        cout << "Memory freed for node with data " << value << endl;
    }
};

class SinglyLinkedList {
    Node* head;
    Node* tail;

public:
    SinglyLinkedList() {
        head = tail = NULL;
    }

    void insertAtHead(int d) {
        if (head == NULL) {
            Node* temp = new Node(d);
            head = tail = temp;
        } else {
            Node* temp = new Node(d);
            temp->next = head;
            head = temp;
        }
    }

    void insertAtTail(int d) {
        if (tail == NULL) {
            Node* temp = new Node(d);
            head = tail = temp;
        } else {
            Node* temp = new Node(d);
            tail->next = temp;
            tail = temp;
        }
    }

    void insertAtPosition(int position, int d) {
        if (position <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }

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

        if (temp == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }

        if (temp->next == NULL) {
            insertAtTail(d);
            return;
        }

        Node* nodeToInsert = new Node(d);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }

    void deleteAtPosition(int position) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if (position <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            if (head == NULL) tail = NULL;
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

            if (current == NULL) {
                cout << "Position out of range!" << endl;
                return;
            }

            previous->next = current->next;
            if (current->next == NULL) {
                tail = previous;
            }
            current->next = NULL;
            delete current;
        }
    }

    void print() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void showHeadTail() {
        if (head != NULL && tail != NULL) {
            cout << "Head: " << head->data << ", Tail: " << tail->data << endl;
        }
    }
};

int main() {
    SinglyLinkedList sll;
    int choice, val, pos;

    do {
        cout << "\n====== Singly Linked List Menu ======\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Position\n";
        cout << "5. Print List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                sll.insertAtHead(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                sll.insertAtTail(val);
                break;

            case 3:
                cout << "Enter position and value: ";
                cin >> pos >> val;
                sll.insertAtPosition(pos, val);
                break;

            case 4:
                cout << "Enter position: ";
                cin >> pos;
                sll.deleteAtPosition(pos);
                break;

            case 5:
                sll.print();
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice, try again!\n";
        }

        sll.showHeadTail();

    } while (choice != 0);

    return 0;
}
