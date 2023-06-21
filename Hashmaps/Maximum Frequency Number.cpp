int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int>mp;

    int maxfreq = 0;
    int maxans = 0;

    for(int i = 0; i<n; i++){
        mp[arr[i]]++;
        maxfreq = max(maxfreq,mp[arr[i]]);
    }
    for(int i=0; i<n; i++){
        if(maxfreq == mp[arr[i]]){
            maxans = arr[i];
            break;
        }
    }
    return maxans;

}
