pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{   int succ=-1;
    int pre=-1;

    while(root->data != key){
        if(root->data >key){
            succ = root -> data;
            root = root -> left;    
        } 
        else{
            pre = root -> data;
            root = root -> right;    
        } 
    }
    
    BinaryTreeNode<int>* leftTree = root->left;
    while(leftTree){
        pre = leftTree->data;
        leftTree = leftTree->right;     
    }  

    BinaryTreeNode<int>* rightTree = root->right;       
    while(rightTree){
        succ = rightTree->data;
        rightTree = rightTree->left;    
    } 

    return {pre,succ};

}
