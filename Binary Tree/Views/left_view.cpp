void solve(Node* root, vector<int> &ans,int lvl){
    if(root == NULL){
        
        return;
    }
    
    if(lvl == ans.size()) ans.push_back(root->data); //Entering new level
    
    solve(root->left,ans,lvl+1);
    solve(root->right,ans,lvl+1);
    
}

vector<int> leftView(Node *root)
{
   vector<int> ans;
   solve(root,ans,0);
   return ans;
}
