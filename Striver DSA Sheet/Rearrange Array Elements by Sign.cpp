// Brute Force

vector<int> rearrangeArray(vector<int>& nums) {
      vector<int> a1,a2;

      for(int i : nums){
          if(i > 0) a1.push_back(i);
          else a2.push_back(i);
      }
      int j = 0;
      for(int i =0;i<nums.size();i += 2){
          nums[i] = a1[j];
          nums[i+1] = a2[j];
          j++;
          
      }
      return nums;
}

// Optimal 

vector<int> rearrangeArray(vector<int>& nums) {
    int i=0;
    int neg = 1,posi = 0;
    int n = nums.size();
    vector<int> ans(n,0);
    while(i<n){
        if(nums[i] > 0){
            ans[posi] =  nums[i];
            posi+= 2;
        }
        else{
            ans[neg] = nums[i];
            neg+=2;
        }
        i++;
    }
    return ans;
}
