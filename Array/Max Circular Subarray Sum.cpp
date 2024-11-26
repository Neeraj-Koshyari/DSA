//Problem Link: https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1


class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int mx = -1e9, mn = 1e9, mxSum = 0, mnSum = 0, total = 0;
        
        for(auto& x: arr){
            mxSum += x;
            mnSum += x;
            total += x;
            
            mx = max(mx, mxSum);
            mn = min(mn, mnSum);
            
            if(mxSum < 0)   mxSum = 0;
            if(mnSum > 0)   mnSum = 0;
        }
        return max(mx, total-mn);
    }
};
