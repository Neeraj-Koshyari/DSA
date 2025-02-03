// Problem Link: https://cses.fi/problemset/task/1631
// Solution Link: https://www.youtube.com/watch?v=s9idnwJEeWg

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    ll sum = 0, x, mx = 0;
    for(int i=0;i<n;i++){
        cin>>x;
        sum += x;
        mx = max(mx, x);
    }

    if((sum - mx) <= mx)  cout<<(2ll*mx)<<endl;
    else cout<<sum<<endl;
    return 0;
}
