// Problem Link: https://codeforces.com/problemset/problem/584/B
// Solution Link: https://www.youtube.com/watch?v=7gDXmmivhSM

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

    ll n, mod = 1e9+7;
    cin>>n;

    ll ans = power(3ll, 3*n, mod) - power(7ll, n, mod);
    cout<<(ans + mod)%mod<<endl;

    return 0;
}
