#include <bits/stdc++.h> 
int solve(int n){
    if(n==0){
       return 1;
    }
    if(n<0) return 0;
    
    return solve(n-1) + solve(n-2);
}

int solveMem(int n,vector<int> &dp){
    if(n==0){
       return 1;
    }
    if(n<0) return 0;
    
    if(dp[n] != -1) return dp[n]% 1000000007;
    
    dp[n] = solveMem(n-1,dp) + solveMem(n-2,dp);
    return dp[n] % 1000000007;
}

int solveTab(int n){
    vector<int> dp(n+1,-1);

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2])% 1000000007;
    }
    return dp[n];
}
int solveOpti(int n){
    int prev1 =1,prev2=1;
    
    for(int i = 2;i<=n;i++){
        int curr = (prev1 + prev2)% 1000000007;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int countDistinctWays(int nStairs) {
    // return solve(nStairs);

    // vector<int> dp(nStairs+1,-1);
    // return solveMem(nStairs,dp);

    // return solveTab(nStairs);

    return solveOpti(nStairs);
    
}
