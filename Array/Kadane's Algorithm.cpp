// Problem Link: https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int mx = -1e9, sum = 0;
        for(auto& x:arr){
            sum += x;
            mx = max(mx,sum);
            
            if(sum < 0) sum = 0;
        }
        return mx;
    }
};
