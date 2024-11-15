// Problem Link : https://www.naukri.com/code360/problems/sort-an-array-in-wave-form_975285

vector<int> waveFormArray(vector<int> &arr, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());

    vector<int> ans;
    for(int i=0;i<n/2;i++){
        ans.push_back(arr[n/2 + i]);
        ans.push_back(arr[i]);
    }
    if(n&1) ans.push_back(arr[n-1]);
    return ans;
}
