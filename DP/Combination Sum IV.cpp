#include <bits/stdc++.h> 
int solve(vector<int> &num, int tar,int n){
    if(tar == 0) return 1;
    if(tar < 0) return 0;
    

    int ans = 0;
    for(int i = 0;i < n;i++){
        ans += solve(num,tar-num[i],n);
    }
    return ans;
}

int solveMem(vector<int> &num, int tar,int n,vector<int> &dp){
    if(tar == 0) return 1;
    if(tar < 0) return 0;
    
    if(dp[tar] != -1) return dp[tar];
    int ans = 0;
    for(int i = 0;i < n;i++){
        ans += solveMem(num,tar-num[i],n,dp);
    }
    dp[tar] = ans;
    return dp[tar];
}

int solveTab(vector<int> &num, int tar,int n){

    vector<int> dp(tar+1,0);

    dp[0] = 1;
    for(int i =1;i<=tar;i++){
        for(int j = 0;j<n;j++){
            if(i-num[j] >= 0) dp[i] += dp[i-num[j]];
        }
    }
    return dp[tar];    
}

int findWays(vector<int> &num, int tar)
{   int n = num.size();

    // return solve(num,tar,n);
    // vector<int> dp(tar+1,-1);
    // return solveMem(num,tar,n,dp);

    return solveTab(num,tar,n);
}
