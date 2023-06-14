int solve(BinaryTreeNode<int>* root, int k,int &i){
    if(root == NULL) return -1;

    int l = solve(root->left,k,i);
    if(l != -1) return l;
    i++;
    if(i == k) return root->data;
   
    return solve(root->right,k,i);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i = 0;
    return solve(root,k,i);
}
