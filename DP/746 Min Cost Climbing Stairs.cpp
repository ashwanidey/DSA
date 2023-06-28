class Solution {
public:
    int solve(int n,vector<int>& cost){
        if(n==0 || n==1) return cost[n];
        if(n<0) return INT_MAX;

        return min(solve(n-1,cost),solve(n-2,cost)) + cost[n];
    }

    int solveMem(int n,vector<int>& cost,vector<int>&dp){
        if(n==0 || n==1) return cost[n];
        
        if(dp[n] != INT_MAX) return dp[n];

        dp[n] = min(solveMem(n-1,cost,dp),solveMem(n-2,cost,dp)) + cost[n];
        return dp[n];
    }

    int solveTab(int n,vector<int>& cost){
        vector<int> dp(n+1,-1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2;i<n;i++){
            dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
        }
        dp[n] = min(dp[n-1],dp[n-2]);
        return dp[n];
    }

    int solveOpti(int n,vector<int>& cost){
        vector<int> dp(n+1,-1);
        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i = 2;i<n;i++){
            int curr = min(prev1,prev2) + cost[i];
            prev2 = prev1;
            prev1= curr;
        }
        int ans = min(prev1,prev2);
        return ans;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // int ans = min(solve(n-1,cost),solve(n-2,cost));
        // return ans;

        // vector<int> dp(n+1,INT_MAX);
        // int ans = min(solveMem(n-1,cost,dp),solveMem(n-2,cost,dp));
        // return ans;

        // return solveTab(n,cost);
        
        return solveOpti(n,cost);
    }
};
