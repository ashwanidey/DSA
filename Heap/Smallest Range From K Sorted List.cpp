// Approach 1 using Heaps
#include<queue>
#include<limits.h>
class node{
    public:
    int data;
    int i;
    int j;

    node(int d,int row,int col){
        data =d;
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


int kSorted(vector<vector<int>> &a, int k, int n) {
    priority_queue<node*,vector<node*>,compare> q;
    int maxi = INT_MIN;
    int mini = INT_MAX;

    for(int i =0;i<k;i++){
        maxi = max(a[i][0],maxi);
        mini = min(a[i][0],mini);
        q.push(new node(a[i][0],i,0));
    }
    int start = mini;
    int end = maxi;

    while(!q.empty()){
        node* top = q.top();
        q.pop();
        mini = top->data;
        if(maxi - mini < end - start){
            start = mini;
            end = maxi;
        }

        if(top->j + 1 < n){
            maxi = max(a[top->i][top->j + 1],maxi);
            q.push(new node(a[top->i][top->j + 1],top->i,top->j + 1));
        }
        else break;
    }
    return end - start +1;
}

// Approach 2 using vectors (TLE)

#include<limits.h>

int kSorted(vector<vector<int>> &a, int k, int n) {
    vector<int> pointer(k,0);
    int ans = INT_MAX;

    while(true){
        int mini =0;
        int maxi = 0;

        // for finding max and min everytime the position of the mini changes
        for(int i = 0;i<k;i++){
            if(a[mini][pointer[mini]] > a[i][pointer[i]]) mini = i;
            if(a[maxi][pointer[maxi]] < a[i][pointer[i]]) maxi = i;
        }

        ans = min(ans,a[maxi][pointer[maxi]]-a[mini][pointer[mini]] + 1);

        if(pointer[mini] + 1 < n) pointer[mini]++;
        else break;
        
    }
    return ans;
}
