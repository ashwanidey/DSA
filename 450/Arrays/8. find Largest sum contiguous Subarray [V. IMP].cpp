class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long msf = INT_MIN;
        long long meh = 0;
        
        for(int i = 0 ;i<n;i++){
            meh += arr[i];
            if(msf < meh) msf = meh;
            if(meh < 0) meh = 0;
        } 
        return msf;
        
    }
};
