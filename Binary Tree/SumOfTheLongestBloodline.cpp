// Approach 1 : From top to bottom
class Solution
{
    private:
    void finder(Node* root,int lvl,int sum,pair<int,int> &ans ){
  
        if((root == NULL)){
            if( lvl == ans.second){
                ans.first = max(sum,ans.first);
            }
            else if(lvl > ans.second){
                ans.first = sum;
                ans.second = lvl;
            }return;
        }
        
        sum = sum + root->data;
        finder(root->left,lvl+1,sum,ans);
        finder(root->right,lvl+1,sum,ans); 
    }
public:  
    int sumOfLongRootToLeafPath(Node *root)
    {
        int sum = 0;
        int lvl = 0;
        pair<int,int> ans = make_pair(INT_MIN,0);
        finder(root,sum,lvl,ans);
        return ans.first;
    }
};

// Approach 2 : From bottom to up
class Solution
{
    private:
    pair<int,int> finder(Node* root){
  
        if(root == NULL){
            return {0,0};
        }
        
        pair<int,int> left = finder(root->left);
        pair<int,int> right = finder(root->right);
        int lh = left.first;
        int rh = right.first;
        int rs = right.second;
        int ls = left.second;
        
        if(lh >= rh){
            if(lh == rh)
                ls = max(ls,rs);
            return {lh+1,ls + root->data};
        }
        else return {rh+1,rs + root->data};
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        return finder(root).second;
    }
};
