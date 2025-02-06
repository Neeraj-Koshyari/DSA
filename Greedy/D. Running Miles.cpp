// Problem Link: https://codeforces.com/problemset/problem/1826/D

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<ll> v(n), pre(n), suff(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            pre[i] = v[i] + i;
            suff[i] = v[i] - i;
        }
        for(int i=1;i<n;i++){
            pre[i] = max(pre[i], pre[i-1]);
            suff[n-1-i] = max(suff[n-1-i], suff[n-i]);
        }

        ll ans = 0;
        for(int i=1;i<n-1;i++)  ans = max(ans, v[i] + pre[i-1] + suff[i+1]);

        cout<<ans<<endl;
    }
    
    return 0;
}
