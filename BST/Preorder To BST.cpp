BinaryTreeNode<int>* createBST(vector<int> &pre,int &i,int min, int max,int n){
    if(i >= n || (pre[i] > max || pre[i] < min)) return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(pre[i++]);
    root->left = createBST(pre,i,min,root->data,n);
    root->right = createBST(pre,i,root->data,max,n);
    return root;
    
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int i = 0;
    return createBST(preorder,i,INT_MIN,INT_MAX,preorder.size());
}
