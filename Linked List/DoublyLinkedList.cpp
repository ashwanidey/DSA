#include<iostream>
#include<math.h>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
        this -> prev = NULL;
    }

     ~Node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head-> next;
    }cout << endl;
}

void insertAtHead(Node* &tail, Node* &head, int d){
    Node* temp = new Node(d);

    // Empty list
    if(head == NULL){
        head,tail = temp;
    }
    else{
        temp -> next= head;
        head -> prev = temp;
        head= temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int d){
    Node* temp = new Node(d);

    // Empty list
    if(tail == NULL){
        head,tail = temp;
    }
    else{
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}


void insertAtPosition(Node* &tail, Node* &head, int position,int d){
    if(position == 1){
        insertAtHead(tail,head,d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt < position -1){
        temp = temp->next;
        cnt++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail,head,d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    temp -> next -> prev = nodeToInsert;
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
     

}

void deleteNode(Node* &head,Node* &tail,int position){
    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        Node* prev = NULL;
        Node* curr = head;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        if(curr -> next != NULL)
        curr -> next -> prev = curr -> prev;
        curr -> next = NULL;
        curr -> prev = NULL;
        

        delete curr;
        if(prev -> next == NULL) tail = prev;
    }
}


int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(tail,head,20);
    print(head);

    insertAtTail(tail,head,50);
    print(head);

   insertAtPosition(tail,head,2,60);
   print(head);

   insertAtPosition(tail,head,5,70);
   print(head);

   insertAtPosition(tail,head,1,80);
   print(head);

   deleteNode(head,tail,5);
   print(head);
   cout << tail->data;

}