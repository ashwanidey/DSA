#define MOD 1000000007
#include<vector>

long long int solve(int n){
    if(n == 1 )return 0;
    if(n == 2) return 1;

    int ans = (n-1) * (solve(n-2) + solve(n-1));
    return ans % MOD;
}

long long int solveMem(int n,vector<long long int> &dp){
    if(n == 1 )return 0;
    if(n == 2) return 1;

    if(dp[n] != -1) return dp[n];

    int ans = (n-1) % MOD * (solveMem(n-2,dp) % MOD + solveMem(n-1,dp) % MOD) % MOD;
    dp[n] = ans % MOD;
    return dp[n];
}

long long int solveTab(int n){
    vector<long long int> dp(n+1,-1);   
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3;i<=n;i++){
        dp[i] = ((i-1) % MOD * (dp[i-2] % MOD + dp[i-1] % MOD) % MOD) % MOD;
    }
    return dp[n];
}

long long int solveOpti(int n){
     
    long long int prev2 = 0;
    long long int prev1 = 1;

    for(int i = 3;i<=n;i++){
        long long int curr = ((i-1) % MOD * (prev2 % MOD + prev1 % MOD) % MOD) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}



long long int countDerangements(int n) {
    // return solve(n);

    // return solveMem(n,dp);

    // return solveTab(n);

    return solveOpti(n);
}
