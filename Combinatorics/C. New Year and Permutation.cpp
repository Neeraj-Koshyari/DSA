// Problem Link : https://codeforces.com/problemset/problem/1284/C
// Solution Link: https://www.youtube.com/watch?v=wV-xHY4qmyI

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll power(ll x, ll y, ll mod){
    ll ans = 1;

    while(y){
        if(y&1) ans = (ans * 1ll * x)%mod;

        x = (x * 1ll * x)%mod;
        y /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    ll n,mod;
    cin>>n>>mod;
    
    vector<ll> fact(n+1);
    fact[0] = 1;
    for(ll i = 1; i<=n; i++)    fact[i] = (fact[i-1] * 1ll * i)%mod;

    ll ans = 0;
    for(ll i = 0; i<n; i++){
        ll val = ((n-i) * 1ll * fact[i+1]) % mod;
        val = (val * 1ll * fact[n-1-i]) % mod;
        val = (val * 1ll * (n-i)) % mod;
        ans = (ans + val)%mod;
    }
    cout<<ans<<endl;

    return 0;
}
