class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
       sort(arr,arr+n);
       
       int mini = arr[0];
       int maxi = arr[n-1];
       int ans = maxi- mini; 
       
       
       for(int i =0;i<n;i++){
           if(arr[i] < k){
               continue;
           } 
           
          mini = min(arr[0]+k,arr[i] - k); // find min from first element and the index element
           maxi = max(arr[i-1] + k,arr[n-1]-k); // find max from last element and the index element
           ans = min(ans,maxi-mini);  // update ans according to the changed min and max
    
       }
       return ans;
    }
};
