void merge(vector<int>& arr, int s, int e){
    int mid = (s+e)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];
    int arrayIndex = s;
    for(int i =0;i<len1;i++){
        arr1[i] = arr[arrayIndex++];
    }
    arrayIndex = mid + 1;
    for(int i =0;i<len2;i++){
        arr2[i] = arr[arrayIndex++];
    }

    int i = 0;
    int j = 0;
    int index = s;

    while(i < len1 && j < len2){
        if(arr1[i] < arr2[j]) arr[index++] = arr1[i++];
        else{
            arr[index++] = arr2[j++];
        }
    }
    while(i<len1) arr[index++] = arr1[i++];
    while(j < len2) arr[index++] = arr2[j++];
}

void solve(vector<int>& arr, int s, int e){
    if(s>= e) return;

    int mid = (s+e)/2;
    solve(arr,s,mid);
    solve(arr,mid+1,e);
    merge(arr,s,e);
}

void mergeSort(vector<int>& arr, int s, int e) {

    solve(arr,s,e);
}
