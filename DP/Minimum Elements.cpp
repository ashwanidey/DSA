#include <bits/stdc++.h> 
int solve(vector<int> &num,int x,int n){
    if(x==0) return 0;
    if(x<0) return INT_MAX;

    int mini = INT_MAX;
    
    for(int i =0;i<n;i++){
        int ans = solve(num,x-num[i],n);
        if(ans != INT_MAX)
        mini = min(mini,ans+1);
    }
    return mini;
}

int solveMem(vector<int> &num,int x,int n,vector<int> &dp){
    if(x==0) return 0;
    if(x<0) return INT_MAX;

    int mini = INT_MAX;

    if(dp[x] != -1) return dp[x];
    
    for(int i =0;i<n;i++){
        int ans = solveMem(num,x-num[i],n,dp);
        if(ans != INT_MAX)
        mini = min(mini,ans+1);
    }
    dp[x] = mini; 
    return dp[x];
}

int solveTab(vector<int> &num,int x,int n){
   vector<int> dp(x+1,INT_MAX);

   dp[0] = 0;

   for(int i =1;i<=x;i++){
       for(int j = 0;j<n;j++){
           if(i-num[j] < dp.size() && dp[i-num[j]] != INT_MAX)
           dp[i] = min(dp[i],dp[i-num[j]] + 1);
       }
   }
   return dp[x];

}

int minimumElements(vector<int> &num, int x)
{   int n = num.size();

    // int ans = solve(num,x,n);
    // if(ans == INT_MAX) return -1;
    // else return ans;

    // vector<int> dp(x+1,-1);
    // int ans = solveMem(num,x,n,dp);
    // if(ans == INT_MAX) return -1;
    // else return ans;

    int ans = solveTab(num,x,n);
    if(ans == INT_MAX) return -1;
    else return ans;
}
