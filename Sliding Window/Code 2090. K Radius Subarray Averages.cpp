// Problem Link: https://leetcode.com/problems/k-radius-subarray-averages/description/
// Youtube Link: https://www.youtube.com/watch?v=aiCHbOFGrRQ

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        long long len = min(n, 2*k + 1), sum = 0;

        vector<int> ans(n,-1);

        for(int i=0;i<len-1;i++)  sum += nums[i];

        for(int i=k; i<n-k; i++){
            sum += nums[i+k];
            ans[i] = sum/len;
            sum -= nums[i-k];
        }

        return ans;
    }
};

// Prefix sum
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size(), len = 2*k + 1;

        vector<long long> temp(n);
        temp[0] = nums[0];

        for(int i=1; i<n; i++)    temp[i] = temp[i-1] + nums[i];

        for(int i=0; i<n; i++){
            if(i-k < 0 || i+k >= n) nums[i] = -1;
            else if(i-k == 0)   nums[i] = temp[i+k]/len;
            else    nums[i] = (temp[i+k] - temp[i-k-1]) / len;
        }
        return nums;
    }
};
