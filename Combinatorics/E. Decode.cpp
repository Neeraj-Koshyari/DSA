// Problem Link: https://codeforces.com/problemset/problem/1996/E

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        int n = s.length(), mod = 1e9+7, count = 0;
        ll ans = 0;
        map<int, ll> mp;
        mp[0] = 1;
        for(int i=0;i<n;i++){
            if(s[i] == '0') count += 1;
            else count -= 1;

            ll x = mp[count];
            ll val = (x * 1ll * (n-i))%mod;
            ans = (ans + val)%mod;

            mp[count] = (mp[count] + (i+2))%mod;
        }
        cout<<ans<<endl;
    }

    return 0;
}
