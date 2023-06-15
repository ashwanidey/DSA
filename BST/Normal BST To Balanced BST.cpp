void inorder(TreeNode<int>* root, vector<int> &in){
    if(root == NULL) return;

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

TreeNode<int>* inToTree(vector<int> in,int s,int e){
    if(s>e) return NULL;
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);

    root->left = inToTree(in, s, mid-1);
    root->right = inToTree(in, mid+1, e);
    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> in;
    inorder(root, in);
    TreeNode<int>* ans = inToTree(in,0,in.size()-1);
    return ans;
}
