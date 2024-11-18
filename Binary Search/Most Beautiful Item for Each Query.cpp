// Problem Link: https://leetcode.com/problems/most-beautiful-item-for-each-query/description/

class Solution {
public:
    static bool cmp(vector<int>& x, vector<int>& y){
        return x[0] < y[0];
    }

    int find(int x, vector<vector<int>>& items){
        if(x < items[0][0]) return -1;

        int l = 0, r = items.size();
        while(l+1 < r){
            int mid = (l+r)/2;

            if(items[mid][0] <= x)  l = mid;
            else r = mid;
        }
        return l;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), cmp);

        int n = items.size();
        vector<int> v(n),ans;
        v[0] = items[0][1];

        for(int i=1;i<n;i++)    v[i] = max(v[i-1], items[i][1]);

        for(auto& x:queries){
            int idx = find(x,items);
            
            if(idx == -1)   ans.push_back(0);
            else ans.push_back(v[idx]);
        }

        return ans;
    }
};
