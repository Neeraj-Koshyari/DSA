// Problem Link: https://codeforces.com/problemset/problem/288/B
// Solution Link: https://codeforces.com/blog/entry/7225

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k, mod = 1e9+7;
    cin>>n>>k;

    vector<ll> v = {1,1,2,9,64,625,7776,117649,2097152};
    ll ans = v[k];
    for(ll i = k+1; i<=n; i++)    ans = (ans * 1ll * (n-k))%mod;

    cout<<ans<<endl;

    return 0;
}
