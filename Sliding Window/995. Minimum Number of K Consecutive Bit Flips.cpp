// Problem Link: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/
// Youtube Link: https://www.youtube.com/watch?v=WdebkzDt3os

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v(n+1);

        int flips = 0, ans = 0;
        for(int i=0;i<=n-k;i++){
            flips += v[i];

            if(flips & 1) nums[i] = 1 - nums[i];

            if(nums[i] == 0){
                v[i + k] = -1;
                flips++;

                ans++;

                nums[i] = 1;
            }
        }

        for(int i=n-k+1; i < n; i++){
            flips += v[i];

            if(flips & 1)    nums[i] = 1 - nums[i];

            if(nums[i] == 0)    return -1;
        }

        return ans;
    }
};
