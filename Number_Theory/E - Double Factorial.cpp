// Problem Link: https://atcoder.jp/contests/abc148/tasks/abc148_e
// Solution Link: https://www.youtube.com/watch?v=ICqrr-wCiy4

/* 
Hint: 
  50 * 2 = 100
  250 * 4 = 1000
  
every 5th generate extra zero
  */

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, ans = 0;
    cin>>n;
    
    if(n&1) cout<<0<<endl;
    else{
        n /= 2;
        for(ll i =5; i<=n; i*=5)    ans += n/i;

        cout<<ans<<endl;
    }

    return 0;
}
