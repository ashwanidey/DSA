#include <bits/stdc++.h> 
int solve(vector<int> &nums,int i){
    if(i < 0) return 0;
    if(i == 0) return nums[0];
    
    int inc = solve(nums,i-2) + nums[i];
    int exc  = solve(nums,i-1) + 0;
    return max(inc,exc);
}

int solveMem(vector<int> &nums,int i,vector<int> & dp){
    if(i < 0) return 0;
    if(i == 0) return nums[0];
    
    if(dp[i] != -1) return dp[i];

    int inc = solveMem(nums,i-2,dp) + nums[i];
    int exc  = solveMem(nums,i-1,dp) + 0;

    dp[i] = max(inc,exc);
    return dp[i];
}

int solveTab(vector<int> &nums,int n){
    vector<int> dp(n+1,0);
    dp[0] = nums[0];
 
    for(int i =1;i<=n;i++){
        dp[i] = max(dp[i-2] + nums[i],dp[i-1]);
    }
    return dp[n];
}

int solveOpti(vector<int> &nums,int n){
    
    int prev1= nums[0];
    int prev2 = 0;
 
    for(int i =1;i<=n;i++){
        int curr = max(prev2 + nums[i],prev1);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    int i = nums.size() - 1;

    // return solve(nums,i);

    // vector<int> dp(i+1,-1);
    // return solveMem(nums,i,dp);

    // return solveTab(nums,i);
    return solveOpti(nums,i);


}
