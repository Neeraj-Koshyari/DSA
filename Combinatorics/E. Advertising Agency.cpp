// Problem Link: https://codeforces.com/problemset/problem/1475/E
// Solution Link: https://www.youtube.com/watch?v=hSK9Qms1EgI

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll power(ll x, ll y, ll mod){
    ll res = 1;
    while(y){
        if(y&1) res = (res * 1ll * x)%mod;

        x = (x * 1ll * x)%mod;
        y/=2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N = 1e3 + 1, mod = 1e9+7;
    vector<ll> fact(N), inv_fact(N);
    fact[0] = 1;
    for(ll i=1;i<N;i++) fact[i] = (fact[i-1] * 1ll * i)%mod;

    inv_fact[N-1] = power(fact[N-1], mod - 2, mod);
    for(ll i=N-2; i>=0; i--)    inv_fact[i] = (inv_fact[i+1] * 1ll * (i+1))%mod;

    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        map<ll,ll, greater<ll>> mp;
        vector<ll> v(n);
        for(int i=0;i<n;i++){    
            cin>>v[i];
            mp[v[i]]++;
        }

        ll ans = 1, taken = 0;
        for(auto& x: mp){
            ll rem = k - taken;
            ll a = x.second;
            ll r = min(rem, x.second);
            ll aCr = ((fact[a] * 1ll * inv_fact[r]) % mod * 1ll * inv_fact[a-r])%mod;
            ans = (ans * 1ll * aCr)%mod;

            taken += r;

            if(taken == k)  break;
        }
        cout<<ans<<endl;
    }

    return 0;
}
