//Problem Link: https://leetcode.com/problems/find-indices-with-index-and-value-difference-ii/

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int mx = -1, mn = 1e9+1, mx_idx = -1, mn_idx = -1, n = nums.size();

        for(int i = indexDifference; i<n; i++){
            if(mx < nums[i-indexDifference]){
                mx = nums[i - indexDifference];
                mx_idx = i - indexDifference;
            }

            if(abs(mx - nums[i]) >= valueDifference)    return {mx_idx, i};

            if(mn > nums[i-indexDifference]){
                mn = nums[i - indexDifference];
                mn_idx = i - indexDifference;
            }

            if(abs(mn - nums[i]) >= valueDifference)    return {mn_idx, i};
        }

        return {-1,-1};
    }
};
