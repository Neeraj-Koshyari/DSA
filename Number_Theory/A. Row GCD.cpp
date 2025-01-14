// Problem Link: https://codeforces.com/problemset/problem/1458/A
// Solution Link: https://www.youtube.com/watch?v=7pUBgzpN5Uk

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,m, hcf = 0, first;
    cin>>n>>m;

    cin>>first;
    for(int i=1;i<n;i++){
        ll x;
        cin>>x;
        hcf = gcd(hcf, x-first);
    }
    for(int i=0;i<m;i++){
        ll x;
        cin>>x;

        cout<<gcd(first+x, hcf)<<" ";
    }

    return 0;
}
