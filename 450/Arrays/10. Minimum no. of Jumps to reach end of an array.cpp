
//Solution : https://www.geeksforgeeks.org/minimum-number-jumps-reach-endset-2on-solution/
class Solution{
  public:
    int minJumps(int arr[], int n){
        int maxReach = arr[0];
        int steps = arr[0];
        int jumps = 1;
        
        // Edges Cases
        if(n <= 1) return 0;
        if(arr[0] == 0) return -1;
        if (arr[0] >= n-1)
          return 1;
        
        for(int i =1;i<n;i++){
            if(i == n-1) return jumps;
            
            if (arr[i] >= (n-1) - i)
              return jumps + 1;
            
            maxReach = max(maxReach,i + arr[i]);
            steps--;
            
            if(steps == 0){
                jumps++;
                if(i >= maxReach) return -1;
                steps = maxReach - i;
            }
            
        }
    }
};
