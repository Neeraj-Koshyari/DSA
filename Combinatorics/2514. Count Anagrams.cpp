// Problem Link: https://leetcode.com/problems/count-anagrams/description/

#define ll long long int
class Solution {
public:
    ll mod = 1e9+7;
    vector<ll> fact, inv_fact;
    Solution(){
        int N = 1e5+1;
        fact.resize(N);
        inv_fact.resize(N);
        
        fact[0] = 1;
        for(ll i = 1ll; i<N; i++)   fact[i] = (fact[i-1] * 1ll * i)%mod;

        auto power = [&](ll x, ll y){
            ll res = 1;
            while(y){
                if(y&1) res = (res * 1ll * x)%mod;

                x = (x * 1ll * x)%mod;
                y /= 2;
            }
            return res;
        };

        inv_fact[N-1] = power(fact[N-1], mod-2);
        for(ll i=N-2; i>=0; i--)    inv_fact[i] = (inv_fact[i+1] * 1ll * (i+1))%mod;
    }
    int countAnagrams(string s) {
        ll count = 0, n = s.length(), ans = 1;

        vector<ll> v(26);
        for(int i=0;i<n;i++){
            if(s[i] == ' '){
                ans = (ans * fact[count])%mod;
                for(auto& x:v){
                    ans = (ans * inv_fact[x])%mod;
                    x = 0;
                }
                count = 0;
            }
            else{
                v[s[i] - 'a']++;
                count++;
            }
        }
        ans = (ans * fact[count])%mod;
        for(auto& x:v)  ans = (ans * inv_fact[x])%mod;

        return ans;
    }
};
