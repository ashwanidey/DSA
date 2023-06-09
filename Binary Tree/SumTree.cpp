class Solution
{   
    private: 
    pair<bool,int> fast(Node* root){
        if(root == NULL){
            pair<bool, int> ans = make_pair(true,0);
            return ans;
        }
        if(root -> left == NULL && root -> right == NULL){
            pair<bool, int> ans = make_pair(true,root->data);
            return ans;
        }
        pair<bool, int> left = fast(root->left);
        pair<bool, int> right = fast(root->right);
        
        bool isLeft = left.first;
        bool isright = right.first;
        bool sum = left.second + right.second == root->data;
        
        pair<bool,int> ans;
        if(isLeft && isright && sum){
            ans.first = true;
            ans.second = 2*(left.second + right.second);
            
        }
        else ans.first = false;
        return ans;
    }
    public:
    bool isSumTree(Node* root)
    {
         return fast(root).first;
    }
};
