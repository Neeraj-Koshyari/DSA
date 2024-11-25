// Problem Link: https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/

class Solution {
public:
    bool ok(int x, vector<int>& v, int k){
        int l = 0, n = v.size(), count = 0;
        for(int r=0; r<n; r++){
            while(v[r] - v[l] > x)  l++;
            count += (r-l);
        }
        return count >= k;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int l = -1, r = 1e6;
        while(l+1 < r){
            int mid = (l+r)/2;

            if(ok(mid,nums,k))  r = mid;
            else l = mid;
        }
        return r;
    }
};
