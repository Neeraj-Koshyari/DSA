// Problem Link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/?envType=problem-list-v2&envId=binary-search
// This Problem can also be solved by C++ STL: Policy based data structures


class Solution {
public:
    vector<int> ans;

    void merge(int l, int mid, int r, vector<pair<int,int>>& nums){
        int n = mid-l+1, m = r-mid;
        vector<pair<int,int>> left(n), right(m);

        for(int i=0;i<n;i++)    left[i] = nums[i+l];
        for(int i=0;i<m;i++)    right[i] = nums[mid+1+i];

        int i = 0, j = 0, k = l, count = 0;
        while(i<n && j<m){
            if(left[i].first <= right[j].first){
                ans[left[i].second] += count;
                nums[k] = left[i];
                i++;
            }
            else{
                nums[k] = right[j];
                j++;
                count++;
            }
            k++;
        }

        while(i<n){
            ans[left[i].second] += count;
            nums[k] = left[i];
            i++;
            k++;
        }

        while(j<m){
            nums[k] = right[j];
            j++;
            k++;
        }
    }

    void find(int l, int r, vector<pair<int,int>>& nums){
        if(l < r){
            int mid = (l+r)/2;
            find(l,mid,nums);
            find(mid+1,r,nums);
            merge(l,mid,r,nums);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> v;
        int n = nums.size();
        ans.resize(n);

        for(int i=0;i<n;i++)    v.push_back({nums[i],i});

        find(0,n-1,v);
        return ans;
    }
};
