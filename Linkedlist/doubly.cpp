//  #include<iostream>
//  using namespace std;

//  class Node{
//     public:
//     int data;
//     Node* next;
//     Node* prev;

//     //constructor
//     Node(int d){
//         this->data=d;
//         this->next= NULL;
//         this->prev = NULL;
//     }
//       ~Node(){
//          int value = this->data;
//          cout<<"the memory is free for node of data "<<value<<endl;
//       }
//  };

//  void insertAtHead(Node* &tail , Node* &head , int d){
//    if(head == NULL){
//      Node* temp = new Node(d);
//      head = temp;
//      tail = temp;
//    }
//    else{
//     Node* temp = new Node(d);
//     temp->next = head;
//     head->prev = temp;
//     head = temp;
//    }
   
//  }

//  void insertAtTail(Node* &tail ,Node* &head,  int d){
//      if(tail == NULL){
//         Node* temp = new Node(d);
//         tail = temp;
//         head = temp;
//      }else{
//       Node* temp = new Node(d);
//      tail->next = temp;
//      temp->prev = tail;
//      tail = temp;

//      }
//  }

//  void insertAtPosition(Node* &tail , Node* &head , int position ,int d){
//     if(position==1){
//         insertAtHead(tail , head , d);
//         return;
//     }
     
//     Node* temp = head;
//     int cnt=1;

//     while(cnt<position-1){
//         temp = temp->next;
//         cnt++;
//     }
   
//     //inserting last position
//     if(temp->next == NULL){
//         insertAtTail(tail ,head , d);
//         return;
//     }

//     Node* nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next;
//     temp->next->prev = nodeToInsert;
//     temp->next = nodeToInsert;
//     nodeToInsert->prev = temp;

//  }

//  void deleteNode(int position , Node* &tail , Node* &head){
//     if(position==1){
   
//         Node* temp = head;
//         temp ->next->prev = NULL;
//         head = temp ->next;
//         temp ->next = NULL;
//         delete temp;
//     }
//     else{
//           //deleting any middle node or last node
//         Node* current = head;
//         Node* previous = NULL;
//         int cnt=1;
//         while(cnt<position && current!=NULL){
//             previous = current;
//             current=current->next;
//             cnt++;
//         }

//         if(current==NULL) return; // position out of range

//         current->prev = NULL;
//         previous ->next = current->next;
//         current->next  = NULL;
//         delete current;
//     }
//  }

// //traversing a linked list
//  void print(Node* head){
//     Node* temp = head;
    
//     while(temp!=NULL){
//        cout<<temp->data<<" ";
//        temp=temp->next;
//     }
//     cout<<endl;
//  }

//  //linkedlist length
//  int getLength(Node* head){
//     int len = 0;
//     Node* temp = head;

//     while(temp!=NULL){
//     len++;
//     temp = temp->next;
//     }
//     return len;
//  }


//  int main(){
//    //  Node* node1= new Node(10);
    
//    //  Node* head = node1;
//    //  Node* tail = node1;
//     // cout<<getLength(head);//length of linkedlist
//    //  print(head);


//    Node* head = NULL;
//    Node* tail = NULL;

//     insertAtHead(tail , head, 20);
//     print(head);

//      insertAtHead(tail , head, 30);
//     print(head);

//     insertAtTail(tail ,head ,  5);
//     print(head);

//    cout<<"head"<<head->data<<endl;
//    cout<<"tail"<<tail->data<<endl;

//    insertAtPosition(tail , head , 4 , 100);
//    print(head);

//    deleteNode(5,tail , head);
//    cout<<"head"<<head->data<<endl;
//    cout<<"tail"<<tail->data<<endl;
//     return 0;
//  }






#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // constructor
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

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtHead(int d) {
        if (head == NULL) {
            Node* temp = new Node(d);
            head = temp;
            tail = temp;
        }
        else {
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
        }
        else {
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
            if (head->next != NULL) {
                head->next->prev = NULL;
            }
            head = temp->next;
            temp->next = NULL;
            delete temp;
        }
        else {
            Node* current = head;
            Node* previous = NULL;
            int cnt = 1;
            while (cnt < position && current != NULL) {
                previous = current;
                current = current->next;
                cnt++;
            }

            if (current == NULL) return; // position out of range

            if (current->next != NULL) {
                current->next->prev = previous;
            }
            else {
                tail = previous; // updating tail if last node is deleted
            }

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

int main() {
    DoublyLinkedList dll;
    int choice, data, position;

    while (true) {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete Node\n";
        cout << "5. Display List\n";
        cout << "6. Get Length\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            dll.insertAtHead(data);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            dll.insertAtTail(data);
            break;
        case 3:
            cout << "Enter position: ";
            cin >> position;
            cout << "Enter data: ";
            cin >> data;
            dll.insertAtPosition(position, data);
            break;
        case 4:
            cout << "Enter position to delete: ";
            cin >> position;
            dll.deleteNode(position);
            break;
        case 5:
            cout << "List: ";
            dll.print();
            break;
        case 6:
            cout << "Length: " << dll.getLength() << endl;
            break;
        case 7:
            exit(0);
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
