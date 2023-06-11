class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void solve(Node *root,int lvl,vector<int> &ans){
        if(root == NULL){
            return;
        } 
        if(lvl >= ans.size()) ans.push_back(root->data);
        
        solve(root->right,lvl+1,ans);
        solve(root->left,lvl+1,ans);        
    }
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       int lvl =0;
       solve(root,lvl,ans);
       return ans;
    }
};
