// Problem Link: https://codeforces.com/problemset/problem/1569/C
// Solution Link: https://www.youtube.com/watch?v=kmd4C5i_A0I

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

    ll N = 2e5+1, mod = 998244353;
    vector<ll> fact(N), inv_fact(N);
    fact[0] = 1;
    for(ll i=1;i<N;i++) fact[i] = (fact[i-1] * 1ll * i)%mod;

    int t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;
        
        vector<ll> v(n);
        ll mx = 0, smx = 0, count = 0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(mx < v[i]){
                smx = mx;  
                mx = v[i];
            }
            else if(smx < v[i])    smx = v[i];
        }

        if(mx == smx){ cout<<fact[n]<<endl; continue;}
        else if(mx-1 != smx){    cout<<0<<endl; continue;}

        for(int i=0;i<n;i++){
            if(v[i] == smx) count++;
        }

        ll ans = (fact[n] * 1ll * (1 - power(count+1, mod-2, mod)))%mod;
        cout<<(ans + mod)%mod<<endl;
    }

    return 0;
}
