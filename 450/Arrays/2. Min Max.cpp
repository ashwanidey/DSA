class Solution
{
   public:
    int findSum(int A[], int N)
    {   
        int maxi = INT_MIN;
        int mini = INT_MAX;
    	for(int i = 0;i<N;i++){
    	    if(maxi < A[i]) maxi = A[i];
    	    if(mini > A[i]) mini = A[i];
    	}
    	return maxi + mini;
    }
};
