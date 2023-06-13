//approach 1 Iterative
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    while(root){
        if(root->data == x) return true;
        else if(root->data > x) root = root->left;
        else root=root->right;
    }
    return false;
}
//Approach 2 Recursive
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(root == NULL) return false;
    if(root->data == x) return true;
    if(root -> data > x) searchInBST(root->left,x);
    else searchInBST(root->right,x);
    
}
