class Solution
{
    public:
    void solve(Node* root, map<int,int> &order){
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            if(order.find(hd) == order.end()){
                order[hd] = frontNode->data;
            }
            if(frontNode -> left) q.push({frontNode->left,hd-1});
            if(frontNode -> right) q.push({frontNode->right,hd+1});
        }
    }
    
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        map<int,int> order;
        solve(root,order);
        for(auto i : order){
            ans.push_back(i.second);
        }
        return ans;
    }
};
