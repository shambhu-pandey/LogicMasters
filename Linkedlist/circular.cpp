#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        cout<<"Memory freed for node with data: "<<value<<endl;
    }
};

class CircularList{
    Node* head;
    Node* tail;

    public:
    CircularList(){
        head = tail = NULL;
    }

    void insertAtHead(int val){
        Node* newnode = new Node(val);

        if(head==NULL){
            head = tail = newnode;
            tail->next = head;
        }
        else{
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
        }
        else{
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

        if(temp == tail){
            tail = newnode;
        }
    }

    void deleteAtHead(){
        if(head == NULL) return;
        else if(head==tail){
            delete head;
            head = tail = NULL;
        }
        else{
           Node* temp = head;
           head = head->next;
           tail->next = head;

           temp->next = NULL;
           delete temp;
        }
    }

    void deleteAtTail(){
        if(head==NULL)return;
        else if(head == tail){
            delete head;
            head = tail = NULL;
        }
        else{
            Node* temp = tail;
            Node* prev = head;
            while(prev->next != tail){
                prev = prev->next;
            }
            tail = prev;
            tail ->next = head;

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

        if(curr == tail){
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }

    void print(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }

        cout<<head->data<<"->";
        Node* temp = head->next;

        while(temp != head){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<head->data<<" (back to head)"<<endl;
    }
};

int main(){
    CircularList cll;
    int choice, val, pos;

    do{
        cout<<"\n====== Circular Linked List Menu ======\n";
        cout<<"1. Insert at Head\n";
        cout<<"2. Insert at Tail\n";
        cout<<"3. Insert at Position\n";
        cout<<"4. Delete at Head\n";
        cout<<"5. Delete at Tail\n";
        cout<<"6. Delete at Position\n";
        cout<<"7. Print List\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value: ";
                cin>>val;
                cll.insertAtHead(val);
                break;

            case 2:
                cout<<"Enter value: ";
                cin>>val;
                cll.insertAtTail(val);
                break;

            case 3:
                cout<<"Enter position and value: ";
                cin>>pos>>val;
                cll.insertAtPosition(pos, val);
                break;

            case 4:
                cll.deleteAtHead();
                break;

            case 5:
                cll.deleteAtTail();
                break;

            case 6:
                cout<<"Enter position: ";
                cin>>pos;
                cll.deleteAtPosition(pos);
                break;

            case 7:
                cll.print();
                break;

            case 0:
                cout<<"Exiting program...\n";
                break;

            default:
                cout<<"Invalid choice, try again!\n";
        }

    }while(choice != 0);

    return 0;
}
