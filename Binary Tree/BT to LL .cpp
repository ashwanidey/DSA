class Solution
{
    public:
    
    void flatten(Node *root)
    {
        Node* curr = root;
        while(curr){
            if(curr->left){
                Node* pred = curr->left;
                while(pred->right){
                    pred = pred-> right;
                }
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
                
                
            }
            else
                curr = curr->right;
        }
    }
};
