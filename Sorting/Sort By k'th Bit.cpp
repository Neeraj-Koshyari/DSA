// Problem Link : https://www.naukri.com/code360/problems/sort-by-kth-bit_973086

vector<int> sortArrayByKBit(int n, int k, vector<int> &arr) {
    // Write your code here.
    k--;
    vector<int> ans,right;
    for(int i=0;i<n;i++){
        if(arr[i] & (1<<k)) right.push_back(arr[i]);
        else ans.push_back(arr[i]);
    }

    for(auto& x:right)  ans.push_back(x);

    return ans;
}
