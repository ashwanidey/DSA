class Solution {
  public:
    
    void solve(Node* root,map<int,int> &Nodes,int hd){
        queue<pair<Node*,int>> q;
        q.push({root,hd});
        
        while(!q.empty()){
            pair<Node*,int> front = q.front();
            q.pop();
            
            Node* frontNode =front.first;
            int hd = front.second;
            
            Nodes[hd] = frontNode->data;
            
            if(frontNode ->left) q.push({frontNode ->left,hd-1});
            if(frontNode ->right) q.push({frontNode ->right,hd+1});
        }
    }
    
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        map<int,int> Nodes;
        int hd = 0;
        solve(root,Nodes,hd);
        for(auto i : Nodes){
            ans.push_back(i.second);
        }
        return ans;
    }
};
