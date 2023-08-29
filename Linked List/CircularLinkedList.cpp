#include<iostream>
#include<math.h>
#include<map>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        while(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};


void insertNode(Node* &tail,int element, int d){
    Node* temp = new Node(d);
    // for empty list
    if(tail == NULL){
        
        tail = temp;
        temp -> next = temp;
    }
    else{

        Node* curr = tail;
        while(curr -> data != element) curr = curr -> next;

        temp -> next = curr -> next;
        curr -> next = temp;
    }   
}


void print(Node* tail){
    Node* temp = tail;

    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do{
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    while(temp != tail);
        
    
    cout << endl;
}

void deleteNode(Node* &tail,int element){
    if(tail == NULL){
        cout << "The list is empty" << endl;
        return;
    }
    Node* prev = tail;
    Node* curr = prev->next;

    while(curr->data != element){
        prev = curr;
        curr = curr->next;
    }
    prev -> next = curr -> next;
    if(curr == prev){
        tail = NULL;
    }
    else if(tail == curr){
        tail = prev;
    }
    
    curr -> next = NULL;
    delete curr;

    
    
}

bool circularOrNot(Node* head){
    if(head == NULL) {
        return true;
    }

    Node* temp = head->next;
    while(temp != NULL){
        if(temp == head){
            return 1;
        }
        temp = temp -> next;
    }
    return 0;
}

bool detectLoop(Node* head){
    if(head ==NULL) return 0;

    map<Node*,bool> visited;
    Node* temp = head;
    
    while(temp != NULL){
        if(visited[temp] == true){
            return 1;
        }
        visited [temp] = true;
        temp = temp ->  next;
    }
    return 0;

}

Node* floydDetection(Node* head){

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast -> next;
        if(fast != NULL) fast = fast -> next;
        slow = slow -> next;
        if(fast == slow) return slow;
    }
    return NULL;
}

Node* getStartingNode(Node* head){
    if(head == NULL)
        return NULL;

    Node* intersection = floydDetection(head);
    Node* slow = head;
    while(slow != intersection){
        slow = slow-> next;
        intersection = intersection -> next;
    }
    return slow;
}

void removeLoop(Node* head){
    if(head == NULL)
        return ;

    Node* startNode = getStartingNode(head);
    Node* temp = startNode;

    while(temp -> next != startNode){
        temp = temp-> next;
    }
    temp -> next = NULL;
    
    
}

int main(){
    Node* tail = NULL;

   
    insertNode(tail, 5, 3);
    print(tail);

   insertNode(tail, 3, 5);
   print(tail);

   
    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);
    
    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    // deleteNode(tail, 10);
    // print(tail);
    if(circularOrNot(tail)){
        cout << "Circular" << endl;
    }
    else{
        cout << " Not circular" << endl;
    }
   
}