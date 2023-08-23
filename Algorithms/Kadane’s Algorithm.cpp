// https://www.youtube.com/watch?v=w4W6yya1PIc&t=2s
// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

/* 
Initialize:
    max_so_far = INT_MIN
    max_ending_here = 0

Loop for each element of the array

  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
  (c) if(max_ending_here < 0)
            max_ending_here = 0
return max_so_far 
*/
  
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i =0;i<n;i++){
            sum += nums[i];
            maxi = max(maxi,sum);
            if(sum < 0) sum = 0;
        }
        return maxi;
    }
};
