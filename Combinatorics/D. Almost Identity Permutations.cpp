// Problem Link: https://codeforces.com/contest/888/problem/D
// Solution Link: https://www.youtube.com/watch?v=LQTy_pjL7V4

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,k, ans = 0;
    cin>>n>>k;

    if(k>=1)    ans += 1;
    if(k>=2)    ans += (n * (n-1)) / 2;
    if(k>=3)    ans += (n * (n-1) * (n-2))/3;
    if(k>=4)    ans += (n * (n-1) * (n-2) * (n-3) * 3) / 8;

    cout<<ans<<endl;
    
    return 0;
}
