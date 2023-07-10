#include<limits.h>

int solve(int n, int x, int y, int z){
	if(n < 0) return INT_MIN;
	if(n == 0) return 0;
	
	int xtimes = solve(n-x,x,y,z) + 1;
	int ytimes = solve(n-y,x,y,z) + 1;
	int ztimes = solve(n-z,x,y,z) + 1;

	return max(xtimes,max(ytimes,ztimes));
}

int solveMem(int n, int x, int y, int z,vector<int> &dp){
	if(n < 0) return INT_MIN;
	if(n == 0) return 0;
	
	if(dp[n] != -1) return dp[n];
	int xtimes = solveMem(n-x,x,y,z,dp) + 1;
	int ytimes = solveMem(n-y,x,y,z,dp) + 1;
	int ztimes = solveMem(n-z,x,y,z,dp) + 1;

	dp[n] = max(xtimes,max(ytimes,ztimes));
	return dp[n];
}


int solveTab(int n, int x, int y, int z){
	vector<int> dp(n+1,INT_MIN);
	
	dp[0] = 0;
	
	for(int i = 1;i<=n;i++){
		if(i - x >= 0) dp[i] = max(dp[i], 1 + dp[i - x]);
		if(i - y >= 0) dp[i] = max(dp[i], 1 + dp[i - y]);
		if(i - z >= 0) dp[i] = max(dp[i], 1 + dp[i - z]);
	}
	return dp[n];
}


int cutSegments(int n, int x, int y, int z) {
	// int ans = solve(n,x,y,z);
	// if(ans < 0) return 0;
	// else return ans;

	// vector<int> dp(n+1,-1);
	// int ans = solveMem(n,x,y,z,dp);
	// if(ans < 0) return 0;
	// else return ans;

	int ans = solveTab(n,x,y,z);
	if(ans < 0) return 0;
	else return ans;
}
