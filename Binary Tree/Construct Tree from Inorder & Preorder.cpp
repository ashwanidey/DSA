class Solution{
    public:
    
    int position(int arr[],int element,int start,int end){
        for(int i = start;i <= end;i++){
            if(element == arr[i]){
                return i;
            }
        }
        return -1;
    }
    
    Node* solve(int in[],int pre[], int n,int &index,int start,int end ){
        if(start > end || index >= n) return NULL;
        
        int element = pre[index++];
        Node* root = new Node(element);
        
    int posi = -1;
       posi = position(in,element,start,end);
        
        root->left = solve(in,pre,n,index,start,posi-1);
        root->right = solve(in,pre,n,index,posi+1,end);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int index = 0;
        Node* root = solve(in,pre,n,index,0,n-1);
        return root;
    }
};
