// Problem Link: https://codeforces.com/problemset/problem/343/A
// Solution Link: https://codeforces.com/blog/entry/8860

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,m;
    cin>>n>>m;

    ll ans = 0;
    while(m){
        ans += (n/m);
        n = n%m;
        swap(n,m);
    }
    cout<<ans<<endl;

    return 0;
}
