// Problem Link: https://codeforces.com/problemset/problem/1348/A
// Solution Link: https://www.youtube.com/watch?v=UqKD3InMf08

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

        ll sum = 0;
        sum = (1ll<<n);
        for(int i=1;i<(n/2); i++)   sum += (1ll<<i);
        for(int i=(n/2); i<n; i++)  sum -= (1ll<<i);
        cout<<sum<<endl;
    }

    return 0;
}
