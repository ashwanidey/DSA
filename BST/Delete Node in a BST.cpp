class Solution {
public:
    TreeNode* minValue(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;

        if(root->val == key){
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if(root->left != NULL && root->right != NULL){
                int min = minValue(root->right)->val;
                root->val = min;
                root->right = deleteNode(root->right,min);
                return root;

            }
        } 
        else if(root -> val > key){
            root->left = deleteNode(root->left,key);
            return root;
        }
        else{
            root->right = deleteNode(root->right,key);
            return root;
        }
        return root;
    }
};
