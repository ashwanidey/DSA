class info{
    public:
    int mini;
    int maxi;
    bool isBST;
    int size;
};

info solve(TreeNode<int>* root,int &count){
    if(root == NULL) return {INT_MAX,INT_MIN,true,0};

    info left = solve(root->left,count);
    info right = solve(root->right,count);

    info currnode;
    currnode.size = left.size + right.size + 1;
    currnode.maxi = max(root->data,right.maxi);
    currnode.mini = min(root->data,left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currnode.isBST = true;
    }
    else currnode.isBST = false;

    if(currnode.isBST) count = max(count,currnode.size);
    return currnode;
}

int largestBST(TreeNode<int>* root) 
{
    int ans = 0;
    info ansi = solve(root,ans);
    return ans;
}
