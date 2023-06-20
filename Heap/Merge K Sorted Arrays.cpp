#include <bits/stdc++.h> 
class node{
    public:
  int data;
  int i;
  int j;

  node(int d,int row,int col){
      data = d;
      i = row;
      j = col;
  }  
};
class compare{
    public:
    bool operator()(node* a,node*b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*,vector<node*>,compare> q;
    vector<int> ans;
    for(int i =0;i<kArrays.size();i++){
        node* temp = new node(kArrays[i][0],i,0);
        q.push(temp);
    }

    while(!q.empty()){
        node* temp = q.top();
        q.pop();

        ans.push_back(temp->data);
        if(temp->j + 1< kArrays[temp->i].size()){
            q.push(new node(kArrays[temp->i][temp->j +1],temp->i,temp->j+1));
        }
    }
    return ans;   
}
