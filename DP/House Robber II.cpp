long long int maxAdjSum(vector<int>& valueInHouse, vector<long long int> &dp, int index, int n){
    // Base Case
    if(index >= n) return 0;
    if(dp[index] != -1) return dp[index];
    // include
    long long int ans = valueInHouse[index] + maxAdjSum(valueInHouse, dp, index + 2, n);
    // exclude
    ans = max(ans, maxAdjSum(valueInHouse, dp, index + 1, n));
    return dp[index] = ans;
}


long long int houseRobber(vector<int>& valueInHouse)
{
    // DP: Top Down Approach: Recursive + Memoization.
    // Similar to the maximum adjucent sum problem.
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    int n = valueInHouse.size();
    vector<long long int> dp(n, -1);
    // Minor change: if you include first house then don't include the last house.
    long long int ans = valueInHouse[0] + maxAdjSum(valueInHouse, dp, 2, n - 1);
    // and if you include last house then don't include the first house.
    for(int i = 0; i < n; i++) dp[i] = -1;
    ans = max(ans, maxAdjSum(valueInHouse, dp, 1, n));
    return ans;
}
