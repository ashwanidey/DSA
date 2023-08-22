void selectionSort(vector<int>&arr) {
    int n = arr.size(),i,j,minInd;
    for(i=0;i<n-1;i++){
        minInd = i;
        for(j=i+1;j<n;j++){
            if(arr[minInd] > arr[j]){
                minInd = j;
            }
        }
        if(minInd != i) swap(arr[i],arr[minInd]);
    }
}
