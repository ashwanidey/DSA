class Solution{
    public:
    
    void heapify(vector<int> &a,int element){
        a.push_back(element);
        int i = a.size()-1;
        while(i>0){
            int parent = (i-1)/2;
            if(a[parent] < a[i]){
                swap(a[parent],a[i]);
                i = parent;
            }
            else return;
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        for(int i = 0;i<m;i++){
            // Inserting elements of 1st heaap into second
            heapify(a,b[i]);
        }
        return a;
    }
};
