// Problem Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/
// Solution Link: https://www.youtube.com/watch?v=5ASGC0bVJDw

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();

        vector<pair<int,int>> v;
        for(int i=0; i<n; i++){
            for(int j=0; j<nums[i].size(); j++)    v.push_back({nums[i][j],i});
        }

        sort(v.begin(),v.end());

        map<int,int> mp;
        int left = 0, right = 1e9, l = 0, count = 0, N = v.size();
        for(int i=0; i<N; i++){
            mp[v[i].second]++;

            if(mp[v[i].second] == 1)    count++;

            while(count == n){
                int diff1 = right-left;
                int diff2 = v[i].first - v[l].first;

                if(diff1 > diff2 || 
                (diff1 == diff2 && left > v[l].first)){
                    right = v[i].first;
                    left = v[l].first;
                }
                mp[v[l].second]--;
                if(mp[v[l].second] == 0)   count--;
                l++;
            }
        }
        return {left,right};
    }
};
