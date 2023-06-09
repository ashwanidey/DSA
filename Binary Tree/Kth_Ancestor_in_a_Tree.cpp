// Approach 1 Finding path using vector and storing the ans from back of the vector
void solve(Node *root, int k, int node,int &ans,vector<int> path){
    if(root == NULL) return;
    path.push_back(root->data);
    
    solve(root->left,k,node,ans,path);
    solve(root->right,k,node,ans,path);    
    int size = path.size();
    if(root -> data == node){
        if(size-k-1 >= 0) // ancestor do not exist
        ans = path[size-k-1];   
    }    
    path.pop_back();
}

int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    vector<int> path;
    solve(root,k,node,ans,path);
    return ans;
}

// Approach 2 using recursion
Node* solve(Node *root, int &k, int node){
    if(root == NULL )return NULL;
    if(root ->data == node) return root;
    
    Node* l = solve(root->left, k, node);
    Node* r = solve(root->right, k, node);
    
    if(l != NULL && r == NULL) 
    {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return l;
    }
   
    if(l == NULL && r != NULL) {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return r;
    }
    return NULL;

}

int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root,k,node);
    
    if(ans == NULL || ans->data == node) return -1;
    else return ans->data;
}
