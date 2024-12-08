// Problem Link: https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        
        vector<vector<int>> ans;
        int start = arr[0][0], end = arr[0][1], n = arr.size();
        
        for(int i=1;i<n;i++){
            if(end < arr[i][0]){
                ans.push_back({start,end});
                start = arr[i][0];
                end = arr[i][1];
            }
            else    end = max(end, arr[i][1]);
        }
        ans.push_back({start,end});
        return ans;
    }
};
