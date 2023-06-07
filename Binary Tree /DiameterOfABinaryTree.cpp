// APPROACH 1

class Solution {
    private:
    
    int height(Node* root){
        if(root == NULL ) return 0;
        
        int left = height(root -> left);
        int right = height(root -> right);
        int ans = max(left,right) + 1;
        return ans;
    }

  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        
        if(root == NULL) return 0;
        
        int op1 = diameter(root -> left);
        int op2 = diameter(root -> right);
        int op3 = height(root->left) + 1 + height(root -> right);
        
        int ans = max(op1,max(op2,op3));
        return ans;
    }
};



// APPROACH 2

class Solution {
    private:
    pair<int,int> diameterfast(Node* root){
        if(root == NULL){
            pair<int,int> ans = make_pair(0,0);
            return ans;
        }
        
        pair<int,int> left = diameterfast(root -> left);
        pair<int,int> right = diameterfast(root -> right);
        int height = left.second + 1 + right.second;
        
        pair<int,int> ans;
        ans.first = max(left.first,max(right.first,height));
        ans.second = max(left.second,right.second) + 1;
        return ans;
        
    }
    
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        
        return diameterfast(root).first;
        
    }
};
