class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        for(int i =0;i<n;i++){
            if(arr[i] < k) arr[i] += k;
            else arr[i] -= k;
        }
        sort(arr,arr+n);
        return arr[n-1] - arr[0];
    }
};
