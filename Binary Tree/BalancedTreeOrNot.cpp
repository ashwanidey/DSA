// Approach 1
class Solution{
    private:
    int height(Node* root){
        if(root == NULL) return 0;
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left,right) + 1;
        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
       if(root == NULL) return true;
       
       bool left = isBalanced(root->left);
       bool right = isBalanced(root-> right);
       bool diff = abs(height(root->left) - height(root->right)) <= 1;
       
       if(left && right && diff) return true;
       else return false;
    }
};

// Approach 2
class Solution{
    private:
    pair<bool,int> balancedfaster(Node* root){
        if(root == NULL) {
            pair<bool, int> ans = make_pair(true,0);
            return ans;
        }
        
        pair<bool,int> left = balancedfaster(root->left);
        pair<bool,int> right = balancedfaster(root-> right);
        
        bool isLeft = left.first;
        bool isRight = right.first;
        
        bool diff = abs(left.second - right.second) <= 1;
        
        pair<bool, int> ans;
        
        if(isLeft && isRight && diff) {
        ans.first = true;
        ans.second = max(left.second,right.second) +1;
        }
        else {
            ans.first = false;
        }
        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
       return balancedfaster(root).first;
    }
};
