// Problem Link: https://codeforces.com/problemset/problem/152/C
// Solution Link: https://www.youtube.com/watch?v=Vdsqoj1y6ow

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    vector<string> v(n);
    for(int i=0;i<n;i++)    cin>>v[i];

    ll ans = 1, mod = 1e9+7;
    for(int j=0;j<m;j++){
        set<char> st;
        for(int i=0;i<n;i++)    st.insert(v[i][j]);
        ans = (ans * (ll)st.size()) % mod;
    }
    cout<<ans<<endl;

    return 0;
}
