// Problem Link : https://leetcode.com/problems/nth-magical-number/description/

#define ll long long int
class Solution {
public:

    bool ok(ll x, int posi, int a, int b, ll c){
        ll val = x/a;
        val += x/b;
        val -= x/c;

        return val >= posi;
    }

    int nthMagicalNumber(int n, int a, int b) {
        ll l = 0, r = 1;
        ll lcm = (a*b)/gcd(a,b), mod = 1e9+7;

        while(!ok(r,n,a,b,lcm)){
            l  = r;
            r *= 2;
        }
        while(l+1 < r){
            ll mid = (l+r)/2;

            if(ok(mid, n, a, b, lcm))   r = mid;
            else l = mid;
        }
        return r%mod;
        
    }
};
