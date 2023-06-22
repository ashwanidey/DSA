void rotate(int arr[], int n)
{
    for(int i=0;i<n;i++)
        swap(arr[i],arr[n-1]);
}
