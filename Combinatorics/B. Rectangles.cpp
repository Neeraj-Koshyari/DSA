// Problem Link: https://codeforces.com/problemset/problem/844/B
// Solution Link: https://www.youtube.com/watch?v=--k-9_UCiNc

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,m, ans = 0;
    cin>>n>>m;

    vector<int> row(n), col(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            row[i] += x;
            col[j] += x;
        }
    }

    for(int i=0;i<n;i++){
        ll one = row[i], zero = m - row[i];
        ans += pow(2,one) + pow(2,zero) - 2;
    }
    for(int i=0;i<m;i++){
        ll one = col[i], zero = n - col[i];
        ans += pow(2,one) + pow(2,zero) - 2;
    }

    ans -= (n*m);
    cout<<ans<<endl;

    return 0;
}
