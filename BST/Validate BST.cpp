bool bst(BinaryTreeNode<int> *root,int min,int max){
    if(root == NULL) return true;

    if (root->data <= max && root->data >= min) {

      bool left = bst(root->left,min,root->data);
      bool right = bst(root->right,root->data,max);
      return left && right;
    }
    else{
        return false;
    }
}

bool validateBST(BinaryTreeNode<int> *root) {
    return bst(root,INT_MIN,INT_MAX);
}
