// Problem Link: https://codeforces.com/problemset/problem/1850/F
// Solution Link: https://www.youtube.com/watch?v=2ZKGTxg9D9g

// Used approch similar to Sieve

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
        int n, count = 0, mx = 0;
        cin>>n;

        map<int,int> mp;
        vector<int> hops(n+1);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            mp[x]++;
        }

        for(auto& x: mp){
            if(x.first > n || x.first == 1)    continue;
            for(int j=x.first; j<=n; j+=x.first){
                hops[j] += x.second;
                mx = max(mx, hops[j]);
            }
        }
        cout<<mx+mp[1]<<endl;
    }

    return 0;
}
