// Approach 1 using map for position (GIVES TLE)
Node* solve(int in[], int post[], int n, int &index,int instart,int inend,map<int,int> posi){
    if(index < 0 || instart > inend) return NULL;
    
    int element = post[index--];
    Node* root = new Node(element);
    
    int position = posi[element];
    
    root -> right = solve(in,post,n,index,position+1,inend,posi);
    root -> left = solve(in,post,n,index,instart,position-1,posi);
    
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    int postOrderIndex = n-1;
    map<int,int> position;
    for(int i =0;i<n;i++){
        position[in[i]] = i;
    }
    Node* ans = solve(in,post,n,postOrderIndex,0,n-1,position);
    return ans;
}

// Approach 2 Finding position using a function
int findPosition(int in[],int element,int start,int end){
        for(int i=start;i<=end;i++){
            if(in[i]==element)
                return i;
        }
        return -1;
    }

Node* solve(int in[], int post[], int n, int &index,int instart,int inend){
    if(index < 0 || instart > inend) return NULL;
    
    int element = post[index--];
    Node* root = new Node(element);
    
    int position = findPosition(in,element,instart,inend);
    
    root -> right = solve(in,post,n,index,position+1,inend);
    root -> left = solve(in,post,n,index,instart,position-1);
    
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    int postOrderIndex = n-1;
    Node* ans = solve(in,post,n,postOrderIndex,0,n-1);
    return ans;
}
