class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        long long ans = 0;
        priority_queue<long long,vector<long long>,greater<long long> > minHeap;
        
        for(int i = 0 ; i < n;i++){
            minHeap.push(arr[i]);
        }
        
        while(minHeap.size() > 1){
            long long a = minHeap.top();
            minHeap.pop();
            long long b = minHeap.top();
            minHeap.pop();
            long long temp = a + b;
            minHeap.push(temp);
            ans += temp;
        }
        return ans;
    }
};
