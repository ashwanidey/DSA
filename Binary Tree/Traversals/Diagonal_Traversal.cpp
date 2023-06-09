// Approach 1 Iterative Approach
vector<int> diagonal(Node *root)
{
   vector<int> ans;
   queue<Node*> q;
   q.push(root);

   while(!q.empty()){
       Node* temp = q.front();
       q.pop();
       while(temp){
           
       ans.push_back(temp->data); // Push data
       if(temp->left) q.push(temp->left); // Push left if not null
       temp = temp->right; // Move right
       }
 
   }
   return ans;
}

// Approach 2 recursive

void solve(Node* root,int hd,map<int,vector<int>> &order){
    if(root == NULL) return;
    
    order[hd].push_back(root->data);
    
    solve(root->left,hd+1,order);
    solve(root->right,hd,order);
}
vector<int> diagonal(Node *root)
{
    vector<int> ans;
    map<int,vector<int>> order;
    solve(root,0,order);
    for(auto i : order){
        for(auto j : i.second){
            ans.push_back(j);
        }
    }
    return ans;
}
