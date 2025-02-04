// Problem Link: https://leetcode.com/problems/maximum-score-of-spliced-array/description/
// Solution Link: https://www.youtube.com/watch?v=6LXXAMQZztE

// greedy solution ( video solution )
class Solution {
public:
    int find(vector<int>& a, vector<int>& b){
        int n = a.size(), sum = 0, mx = 0, total = 0;
        for(int i=0; i<n; i++){
            sum += (b[i] - a[i]);
            mx = max(mx, sum);

            if(sum < 0) sum = 0;
            total += a[i];
        }
        return total + mx;
    }

    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(find(nums1, nums2), find(nums2, nums1));
    }
};

// Memoiation
class Solution {
public:
    int find(int idx, vector<int>& a, vector<int>& b, int flag, vector<vector<int>>& dp){
        if(idx < 0) return 0;

        if(dp[idx][flag] != -1) return dp[idx][flag];

        if(flag == 0){
            int val = max(find(idx-1, a, b, 0, dp), find(idx-1, a, b, 1, dp));
            return dp[idx][flag] =  a[idx] + val;
        }
        else if(flag == 1){
            int val = max(find(idx-1, a, b, 2, dp), find(idx-1, a, b, 1, dp));
            return dp[idx][flag] = b[idx] + val;
        }
        return dp[idx][flag] = (a[idx] + find(idx-1, a, b, 2, dp));
    }

    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp1(n, vector<int>(3,-1)), dp2(n, vector<int>(3,-1));
        return max(find(n-1, nums1, nums2, 0, dp1), find(n-1, nums2, nums1, 0, dp2));
    }
};

// Tabulation

class Solution {
public:
    int find(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        vector<vector<int>> dp(n+1, vector<int>(3));

        for(int idx=1; idx<=n; idx++){
            for(int flag = 2; flag>=0; flag--){
                if(flag == 0)
                    dp[idx][0] =  nums1[idx-1] + max(dp[idx-1][0], dp[idx-1][1]);
                else if(flag == 1)
                    dp[idx][1] = nums2[idx-1] + max(dp[idx-1][2], dp[idx-1][1]);
                else
                    dp[idx][2] = nums1[idx-1] + dp[idx-1][2];
            }
        }
        return dp[n][0];
    }

    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(find(nums1, nums2), find(nums2, nums1));
    }
};
