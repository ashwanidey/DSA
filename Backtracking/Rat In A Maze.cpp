#include <bits/stdc++.h>
void solve(int x,int y,vector<vector<int>> &arr,int n,
vector<vector<bool>> &vis,vector<string> & ans,string &path){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    vis[x][y] = 1;

    int newx = x+1;
    int newy = y;
    if(newx < n && arr[newx][newy] == 1 && vis[newx][newy] == 0){
        path.push_back('D');
        solve(newx,newy,arr,n,vis,ans,path);
        path.pop_back();
    }

    newx = x;
    newy = y-1;
    if(newy >= 0 && arr[newx][newy] == 1 && vis[newx][newy] == 0){
        path.push_back('L');
        solve(newx,newy,arr,n,vis,ans,path);
        path.pop_back();
    }
    newx = x;
    newy = y+1;
    if(newy < n && arr[newx][newy] == 1 && vis[newx][newy] == 0){
        path.push_back('R');
        solve(newx,newy,arr,n,vis,ans,path);
        path.pop_back();
    }
    newx = x-1;
    newy = y;
    if(newx >= 0 && arr[newx][newy] == 1 && vis[newx][newy] == 0){
        path.push_back('U');
        solve(newx,newy,arr,n,vis,ans,path);
        path.pop_back();
    }
    vis[x][y] = 0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<vector<bool>> visited(n, vector<bool> (false, n));
     vector<string> ans;
    if(arr[0][0] == 0) return ans;

   
    string path = "";
    solve(0,0,arr,n,visited,ans,path);
    return ans;
}
