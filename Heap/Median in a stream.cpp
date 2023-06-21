#include<queue>

void median(int element,priority_queue<int> &maxHeap,
priority_queue<int,vector<int>,greater<int>> &minHeap,int &median){
	int size = maxHeap.size() - minHeap.size();

	switch(size){
		case 0:
			if(element > median){
				minHeap.push(element);
				median = minHeap.top();
			}
			else{
				maxHeap.push(element);
				median = maxHeap.top();
			}
		break;
		case 1:
			if(element > median){
				
				minHeap.push(element);	
			}
			else{
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(element);
			}
			median = (minHeap.top()+maxHeap.top())/2;
		break;
		case -1:
			if(element > median){
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(element);
			}
			else{
				maxHeap.push(element);
			}
			median = (minHeap.top()+maxHeap.top())/2;
		break;

	}
}

vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;
	priority_queue<int> maxHeap;
	priority_queue<int,vector<int>,greater<int>> minHeap;
	int prevMedian = 0;
	for(int i =0;i<n;i++){
		median(arr[i],maxHeap,minHeap,prevMedian);
		ans.push_back(prevMedian);
	}
	return ans;
}
