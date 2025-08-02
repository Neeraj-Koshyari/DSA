// Problem link: https://leetcode.com/problems/gcd-sort-of-an-array/description/

class Solution {
public:
    int N = 1e5+1;
    vector<int> par, len;
    
    Solution(){
        par.resize(N);
        len.resize(N);

        for(int i=0; i<N; i++){
            par[i] = i;
            len[i] = 1;
        }
    }

    int find(int x){
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void join(int u, int v){
        int pu = find(u), pv = find(v);

        if(pu == pv)    return;

        if(len[pv] > len[pu])   swap(pu, pv);

        len[pu] += len[pv];
        par[pv] = pu;
    }
    bool gcdSort(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        for(auto &x : nums){
            int val = x;
            for(int i=2; i*i <= val; i++){
                if(val%i != 0)  continue;

                join(x,i);
                while(val%i == 0) val /= i;
            }

            if(val != 1)    join(x, val);
        }

        int n = nums.size();
        for(int i=0; i<n; i++){
            if(find(nums[i]) != find(temp[i]))   return false;
        }
        return true;
    }
};
