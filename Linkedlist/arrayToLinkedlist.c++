#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val): data(val) , next(nullptr){}

};

Node* arrayToLinkdelist(int arr[] ,int size){
    if(size==0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* current = head;
    

    //iterate  through the array and create linked list nodes
    for(int i = 1; i<size; i++){
        current-> next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

void printLinkedlist(Node* head){

    Node* current = head;
    while(current !=nullptr){
        cout<<current->data<<" ->";
        current= current->next;
    }

    cout<<"nullptr"<<endl;

}

int main(){
   int arr[] ={1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    Node* head = arrayToLinkdelist(arr ,size);
    printLinkedlist(head);

    return 0;
}