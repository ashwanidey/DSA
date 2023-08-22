void solve(vector<int>&arr, int n){
    if(n==1) return;

    bool swapped = false;
    for(int j = 0;j<n-1;j++){
        if(arr[j] > arr[j+1]){
            swap(arr[j],arr[j+1]);
            swapped = true;
        }
    }
    if(swapped == false) return ;
    solve(arr,n-1);

}

void bubbleSort(vector<int>&arr, int n) 
{
    solve(arr,n);
}
