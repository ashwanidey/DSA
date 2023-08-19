class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        //Marked in place
        //O(n)
        //O(1)

        int n = nums.size();
        for (int num : nums) {
            int idx = abs(num);
            if (nums[idx] < 0) {
                return idx;
            }
            nums[idx] = -nums[idx];
        }
        return n;


        // Sorting
        //O(nlogn)
        //o(logn)

        // sort(nums.begin(),nums.end());
        // int n = nums.size();
        // for(int i =0;i<n-1;i++){
        //     if(nums[i] == nums[i+1]) return nums[i];
        // }
        // if(nums[n-2] == nums[n-1]) return nums[n-2];
        // return -1;
    }
};
