#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include<stack>

class node{
     public:

    int data;
    node *left;
    node *right;

   

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* createTree(node* root){

    cout << "Enter Data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1) return NULL;

    cout << "Enter data for inserting in left of " << data << endl;
    root -> left = createTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root -> right = createTree(root->right);

    return root;

}

void LevelOrderTraversing(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left)
            q.push(temp -> left);
            if(temp -> right) q.push(temp -> right);
        }
    }
}

vector<int> inorder(node* root){
    // if(root == NULL) return;

    // inorder(root->left);
    // cout << root -> data << " ";
    // inorder(root->right);

    vector<int> inorder;
    stack<node*> s;
    while(true){
        if(root != NULL){
            s.push(root);
            root = root -> left;
        }
        else{
            if(s.empty()) break;
            root = s.top();
            inorder.push_back(root->data);
            s.pop();
            root = root -> right;
        }
    }
    return inorder;
}

void preorder(node* root){
    // if(root == NULL) return;

    // cout << root -> data << " ";
    // preorder(root->left);
    // preorder(root->right);

    

}

void Postorder(node* root){
    if(root == NULL) return;

    Postorder(root -> left);
    Postorder(root -> right);
    cout << root -> data << " ";
}

node* buildLevelOrder(node* &root){
    queue<node*> q;
    cout << "Enter data:" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter data for inserting in left of " << temp -> data << endl;
        int leftData;
        cin >> leftData;
        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter data for inserting in right of " << temp -> data << endl;
        int rightData;
        cin >> rightData;
        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main(){

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // node* root = NULL;
    // buildLevelOrder(root);
    // LevelOrderTraversing(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    node* root = NULL;
    root = createTree(root);
    LevelOrderTraversing(root);
    vector<int> ans = inorder(root);
    for(int i : ans) cout << i << " ";
    cout <<endl;
    // preorder(root);
    // cout << endl;
    // Postorder(root);
   

}
