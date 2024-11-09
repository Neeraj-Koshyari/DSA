// Problem Link : https://www.naukri.com/code360/problems/return-subsets-sum-to-k_759331

vector<vector<int>> ans;

void find(vector<int>& arr, int idx, int k,vector<int>& temp){
    if(idx < 0){
      if (k == 0) {
        reverse(temp.begin(), temp.end());
        ans.push_back(temp);
        reverse(temp.begin(), temp.end());
      }
        return;
    }

    find(arr,idx-1,k,temp);
    temp.push_back(arr[idx]);
    find(arr,idx-1,k-arr[idx],temp);
    temp.pop_back();
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<int> temp;
    find(arr,n-1,k,temp);
    return ans;
}
