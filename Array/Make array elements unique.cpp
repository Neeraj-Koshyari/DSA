// Problem Link: https://www.geeksforgeeks.org/problems/make-array-elements-unique--170645/1

class Solution {
  public:
    int minIncrements(vector<int> arr) {
        // Code here
        int ans = 0, val = -1, n = arr.size();
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++){
            if(val >= arr[i]){
                ans += (val-arr[i]+1);
                val++;
            }
            else val = arr[i];
        }
        return ans;
    }
};
