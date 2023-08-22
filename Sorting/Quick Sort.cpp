/*
	The function is called with the parameters:
	quickSort(input, 0, size - 1);

*/

int partitionArray(int input[], int s, int e) {
	int pivot = input[s];
	int count =0;
	

	for(int i =s+1;i<=e;i++){
		if(pivot > input[i]){
			count++;
		}
	}
	int pivotIndex = s+count;
	swap(input[pivotIndex],input[s]);

	int i =s,j=e;
	while(i < pivotIndex && j > pivotIndex){
		while(input[i] <= pivot) i++;
		while(input[j] > pivot) j--;
		if(i < pivotIndex && j > pivotIndex) swap(input[i++],input[j--]);
	}
	return pivotIndex;

}

void solve(int input[], int start, int end) {
	if(start >= end) return;

	int p = partitionArray(input,start,end);
	solve(input,start,p-1);
	solve(input,p+1,end);
}

void quickSort(int input[], int start, int end) {
	
	solve(input,start,end);

}
