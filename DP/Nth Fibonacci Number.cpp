#include<bits/stdc++.h>
using namespace std;

int solve(int n){
        if(n <= 1) return n;
        int ans = solve(n-1) + solve(n-2);
        return ans;
}
int solveMem(int n,vector<int>&dp){
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        dp[n] = solve(n-1) + solve(n-2);
        return dp[n];
}
int solveTab(int n){
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i =2;i<=n;i++){
                dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
}
int solveOpti(int n){   
        int prev2 = 0;
        int prev1 = 1;
        for(int i =2;i<=n;i++){
                int curr = prev1 + prev2;
                prev2 = prev1;
                prev1 = curr;
        }
        return prev1;
}
int main()
{
        int n;
        cin >> n;

        // cout << solve(n) << endl;

        // vector<int> dp(n+1,-1);
        // cout << solveMem(n,dp) << endl;

        // cout << solveTab(n) << endl;

        cout << solveOpti(n) << endl;
}
