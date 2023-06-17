void heafify(vector<int> &arr,int n,int i){ 
    int smallest = i,left =2*i + 1, right = 2*i+2;
  
    if(arr[smallest] > arr[left] && left < n) smallest = left;
    if(arr[smallest] > arr[right] && right < n) smallest = right;

    if(smallest != i){
        swap(arr[i],arr[smallest]);
        heafify(arr,n,smallest);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{   int n = arr.size();
    for(int i = n/2-1;i>=0 ;i--){
        heafify(arr,n,i);
    }
    return arr;
}
