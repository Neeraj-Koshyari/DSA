// Problem Link : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution {
public:
    bool ok(int day, vector<int>& bloomDay, int m, int k){
        int bouquets = 0, count = 0;
        for(auto& x:bloomDay){
            if(x <= day)    count++;
            else count = 0;

            if(count == k){
                bouquets++;
                count = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if((m*1ll*k) > (long long int)bloomDay.size())   return -1;

        int l = 0, r = 1;

        while(!ok(r,bloomDay,m,k)){
            l = r;
            r *= 2;
        }

        while(l+1 < r){
            int mid = (l+r)/2;

            if(ok(mid,bloomDay,m,k))    r = mid;
            else l = mid;
        }
        return r;
    }
};
