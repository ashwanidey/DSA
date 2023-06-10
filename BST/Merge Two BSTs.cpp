// Approach 1 Using vectors
void mergeSortedArray(vector<int> in1,vector<int> in2,vector<int> &in){
    int n1 = in1.size();
    int n2 = in2.size();
    int i = 0,j=0;

    while(i < n1 && j < n2){
      if (in1[i] < in2[j]) {
        in.push_back(in1[i]);
        i++;
      } else{
          in.push_back(in2[j]);
          j++;
      }
   
    }
    while(i < n1){
        in.push_back(in1[i]);
        i++;
      }
    while(j < n2){
          in.push_back(in2[j]);
          j++;
      }
}

void inorder(TreeNode<int>* root,vector<int> &in){
    if(root == NULL) return;

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

TreeNode<int>* inToBST(vector<int> in,int s ,int e){
    if(s > e) return NULL;

    int m = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(in[m]);
    root -> left = inToBST(in,s,m-1);
    root -> right = inToBST(in,m+1,e);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int> in1;
    vector<int> in2;
    inorder(root1,in1);
    inorder(root2,in2);
    vector<int> in;
    mergeSortedArray(in1,in2,in);
    return inToBST(in,0,in.size()-1);
}

// Approach 2 Using linked list
void convertIntoSortedDLL(TreeNode<int> *root, TreeNode<int>* &head)
{
    // base case
    if(root==NULL)
    {
        return;
    }

    convertIntoSortedDLL(root->right, head);

    root->right=head;
    if(head!=NULL)
    {
        head->left=root;
    }
    
    head=root;

    convertIntoSortedDLL(root->left, head);
}

TreeNode<int>* mergeLinkedList(TreeNode<int>* head1, TreeNode<int>* head2)
{
    TreeNode<int>* head=NULL;
    TreeNode<int>* tail=NULL;
    
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data < head2->data)
        {
            if(head==NULL)
            {
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else
            {
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }
        else
        {
            if(head==NULL)
            {
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else
            {
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }
        }
    }

    while(head1!=NULL)
    {
        tail->right=head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;
    }

    while(head2!=NULL)
    {
        tail->right=head2;
        head2->left=tail;
        tail=head2;
        head2=head2->right;
    }
    
    return head;
}

int countNodes(TreeNode<int>* head)
{
    TreeNode<int>* temp=head;
    int cnt=0;
    
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->right;
    }

    return cnt;
}

TreeNode<int>* sortedLLToBST(TreeNode<int>* &head, int n)
{
    // base case
    if(n<=0 || head==NULL)
    {
        return NULL;
    }

    TreeNode<int>* left=sortedLLToBST(head, n/2);

    TreeNode<int>* root=head;
    root->left=left;
    head=head->right;

    root->right=sortedLLToBST(head,n-n/2-1);
    
    return root;
}
    

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    
    // step-1: convert BST into sorted DLL in-place
    TreeNode<int>* head1=NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left=NULL;

    TreeNode<int>* head2=NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left=NULL;

    // step-2: merge two sorted LL
    TreeNode<int>* head=mergeLinkedList(head1, head2);

    // step-3: convert sorted LL into BST
    return sortedLLToBST(head, countNodes(head));
}
