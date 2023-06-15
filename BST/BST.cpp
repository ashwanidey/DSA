#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include<stack>

class node{
    public:
    int data;
    node* right;
    node* left;

    node(int d){
        this -> data = d;
        this ->  right = NULL;
        this ->  left = NULL;
    }
};

node* createBST(node* root,int d){
    
    if(root == NULL ){
        node* temp = new node(d);
        root = temp;
        return root;
    }
    
    if(root->data > d){
        root -> left = createBST(root->left,d);
    }
    else root -> right = createBST(root->right,d);

    return root;
}
//10 8 21 7 27 5 4 3 -1
void insertValues(node* &root){
    int data;
    cin >> data;
    while(data != -1){
        root = createBST(root,data);
        cin >> data;
    }
}

node* minValue(node* root){
    node* temp = root;
    while(temp->left) {
        temp = temp->left;
    }
    return temp;
}
node* maxValue(node* root){
    node* temp = root;
    while(temp->right) {
        temp = temp->right;
    }
    return temp;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* front = q.front();
        q.pop();

        if(front == NULL){
            cout << endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout << front->data << " ";
            if(front -> left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
}

int main(){
    node* root = NULL;
    
    cout << "Enter the data" << endl;
    insertValues(root);
    cout << "Printing Data" << endl;
    levelOrderTraversal(root);
}
