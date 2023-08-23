// HASH TABLE APPROACH O(N) O(N)

#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    unordered_map<int,int> um;
    long long sum = 0;
    int maxLen = 0;

    for(int i =0;i<a.size();i++){
        sum += a[i]; //Accumulate arr[i] to sum.

        if(sum == k) maxLen = i+1; // If sum == k, update maxLen = i+1.

        //Check whether sum is present in the hash table or not. If not present, then add it to the hash table as (sum, i) pair.
        if(um.find(sum) == um.end()) um[sum] = i;

        //Check if (sum-k) is present in the hash table or not. If present then update maxLen to i - (sum-k)
        if(um.find(sum-k) != um.end()){
            maxLen = max(maxLen,i-um[sum-k]);
        }
    }
    return maxLen;
}

// SLIDING WINDOW O(N) O(1)

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int i =0,j=0,maxLen =0,n=a.size();
    long long sum =0;
    
    while(j<n){
        sum += a[j]; // compute sum
        
        if(sum == k) maxLen = max(maxLen,j-i+1); // if found then update maxLen
        
        else if(sum > k){
            while(sum > k) sum -= a[i++]; //Decrease size of window until sum > k
            
            if(sum == k) maxLen = max(maxLen,j-i+1); // check if has become equal to the target or not
        }
        j++; // Increse size of window after every iteration.
    }
    return maxLen;
