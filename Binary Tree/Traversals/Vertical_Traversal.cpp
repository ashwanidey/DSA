class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;
        map<int,map<int,vector<int> > >  order;
        queue<pair<Node*,pair<int,int> > > q;
        
        q.push({root,{0,0}});
        
        while(!q.empty()){
            pair<Node*,pair<int,int> >  temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            order[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left) q.push({frontNode->left,{hd-1,lvl+1}});
            if(frontNode->right) q.push({frontNode->right,{hd+1,lvl+1}});
        }
        
        for(auto i : order){
            for(auto j : i.second){
                for(auto k : j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};
