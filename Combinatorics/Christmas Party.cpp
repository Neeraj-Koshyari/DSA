// Problem Link: https://cses.fi/problemset/task/1717
// Solution Link: https://www.youtube.com/watch?v=Ef_XCFQZb4Q

/*
  Derangement of a number
  D(n) = n! * sumbission from i = 0 to n ( (-1)^i / i! )
  */

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
ll mod_inverse(ll x, ll y, ll mod){
    ll res = 1;
    while(y){
        if(y&1) res = (res*x)%mod;
 
        x = (x*x)%mod;
        y/=2;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n, mod = 1e9+7;
    cin>>n;
 
    vector<ll> fact(n+1);
    fact[0] = fact[1] = 1;
    for(ll i=2;i<=n;i++)    fact[i] = (fact[i-1] * i)%mod;
 
    ll ans = 0;
    for(ll i=0;i<=n;i++){
        if(i&1) ans = (ans - (fact[n] * mod_inverse(fact[i], mod-2, mod)) % mod)%mod;
        else ans = (ans + (fact[n] * mod_inverse(fact[i], mod-2, mod)))%mod;
    }
    cout<<ans<<endl;
 
    return 0;
}
