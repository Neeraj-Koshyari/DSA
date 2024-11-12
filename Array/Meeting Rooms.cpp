// Problem Link : https://www.geeksforgeeks.org/problems/attend-all-meetings/1

class Solution {
  public:
    static bool cmp(vector<int>& x, vector<int>& y){
        return x[0] < y[0];
    }
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        sort(arr.begin(),arr.end(),cmp);
        int last = -1;
        
        for(auto& x:arr){
            if(last > x[0]) return false;
            last = x[1];
        }
        return true;
    }
};
