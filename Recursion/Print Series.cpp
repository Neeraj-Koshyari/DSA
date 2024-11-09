// problem Link : https://www.naukri.com/code360/problems/print-series_1081471

void find(vector<int>& ans, int n, int k){
    ans.push_back(n);
    if(n<=0) return;

    find(ans,n-k,k);
    ans.push_back(n);
}
vector<int> printSeries(int n, int k)
{
    // Write your code here
    vector<int> ans;
    find(ans,n,k);
    return ans;
}
