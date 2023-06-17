#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include<stack>

class heap{
    public: 
    int arr[101];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int data){
        size = size + 1;
        int i = size;
        arr[i] = data;
        while(i > 1){
            int parent = i/2;
            if(arr[parent] < arr[i]){
                swap(arr[parent],arr[i]);
                i = parent;
            }
            else{
                return;
            }
        }
        
    }

    void print(){
        for(int  i = 1;i <= size;i++){
            cout << arr[i] << " " ;
        }cout << endl;
    }

    void deleter(){
        if(size == 0) cout << "Nothing to delete" << endl;

        arr[1] = arr[size];
        size = size -1;
        int i = 1;
        

        while(i<size){
            int left = 2*i,right = 2*i+1;
            if(left <= size && arr[left] > arr[i]){
                swap(arr[left],arr[i]);
                i = left;
            }
            else if(right <= size && arr[right] > arr[i]){
                swap(arr[right],arr[i]);
                i = right;
            }
            else{
                return ;
            }
        }
    }
};

void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i,right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]) largest = right;

    if(largest !=  i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapsort(int a[],int n){
    
    while(n > 1){
        swap(a[1],a[n]);
        n--;
        heapify(a,n,1);
    }
}

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    cout << "Printing the heap" << endl;
    h.print();
    cout <<"Printing after deletion" << endl;
    h.deleter();
    h.print();

    int arr[7] = {-1,89,55,53,52,4,2};
    int n= 6;

    for(int i = n/2;i> 0;i--){
        heapify(arr,n,i);
    }
    for(auto i : arr) cout << i << " ";
    cout << endl;

    cout << " Sorted ARRAY" << endl;
    heapsort(arr,n);
    for(auto i : arr) cout << i << " ";
}
