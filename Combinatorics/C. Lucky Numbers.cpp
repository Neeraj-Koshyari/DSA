// Problem Link: https://codeforces.com/problemset/problem/630/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    ll ans = 0, p = 1;
    for(int i=0;i<n;i++){
        p *= 2ll;
        ans += p;
    }
    cout<<ans<<endl;
    return 0;
}
