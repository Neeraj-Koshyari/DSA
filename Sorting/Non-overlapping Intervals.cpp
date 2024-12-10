// Problem Link: https://www.geeksforgeeks.org/problems/non-overlapping-intervals/1

class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        
        int end = 0, ans = 0;
        for(int i=0;i<n;i++){
            if(end <= intervals[i][0])  end = intervals[i][1];
            else{
                ans++;
                end = min(end,intervals[i][1]);
            }
        }
        return ans;
    }
};
