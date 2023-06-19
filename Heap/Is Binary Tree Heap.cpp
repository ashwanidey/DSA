class Solution {
  public:
    
    int counter(struct Node* tree){
        int count= 0;
        queue<struct Node*> q;
        q.push(tree);
        while(!q.empty()){
            struct Node* temp = q.front();
            q.pop();
            count++;
            
            if(temp->left) q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        return count;
    }
    
    bool isCBT(struct Node* tree,int i,int count){
        if(tree == NULL) return true;
        
        if(i >= count ) return false;
        else{
            return isCBT(tree->left,2*i + 1,count) && isCBT(tree->right,2*i + 2,count);
        }
    }
    

    bool maxHeap(struct Node* tree){
        if(tree -> left == NULL && tree -> right == NULL) {
            return true;
        } 
        else if(tree->right == NULL) return tree->data > tree->left -> data;
        else{
            bool left = maxHeap(tree->left);
            bool right = maxHeap(tree->right);
            return left && right && (tree->data > tree ->left ->data && tree->data > tree->right -> data); 
        }
    }
    

    
    bool isHeap(struct Node* tree) {
        int index = 0;
        int count = counter(tree);
      
        
        return  isCBT(tree,index,count) && maxHeap(tree);
    }
};
