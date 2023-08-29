#include<iostream>
#include<math.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }


};

bool circularOrNot(Node* head){
    Node* temp = head->next;
    while(temp != NULL){
        if(temp == head){
            return 1;
        }
        temp = temp -> next;
    }
    return 0;
}

void deleteNode(int position, Node* &head,Node* &tail){
    
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp; 
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        if(prev->next == NULL) tail = prev;
        delete curr;
    }
}

void insertAtHead(Node* &head,int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;

}

void insertAtTail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void insertAtPosition(Node* &tail,Node* &head,int position,int d){
    if(position == 1){
        insertAtHead(head,d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt < position -1){
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail,d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void print(Node* head){

    // Node* temp = head;
    while(head != NULL){
        cout << head -> data << " " ;
        head = head -> next;
    }cout << endl;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head,20);
    print(head);

    insertAtTail(tail,30);
    print(head);

    insertAtPosition(tail,head,2,100);
    print(head);

    insertAtPosition(tail,head,3,3);
    print(head);

    insertAtPosition(tail,head,6,200);
    print(head);

    insertAtPosition(tail,head,1,900);
    print(head);

    if(circularOrNot(head)){
        cout << "Circular" << endl;
    }
    else{
        cout << " Not circular" << endl;
    }

    // deleteNode(7,head,tail);
    // print(head);
    // cout << tail->data ;

    // deleteNode(6,head,tail);
    // print(head);
    // cout << tail->data ;
    // deleteNode(4,head,tail);
    // print(head);
    // cout << tail->data ;

}