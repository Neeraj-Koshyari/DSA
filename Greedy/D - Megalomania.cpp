// Problem Link: https://atcoder.jp/contests/abc131/tasks/abc131_d
// Solution Link: https://www.youtube.com/watch?v=2QGDjYtR1U0

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

    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)    cin>>v[i].second>>v[i].first;

    sort(v.begin(),v.end());

    ll t = 0;
    for(int i=0;i<n;i++){
        if(v[i].first < (t + v[i].second)){
            t = -1;
            break;
        }
        t += v[i].second;
    }
    if(t == -1) cout<<"No\n";
    else cout<<"Yes\n";

    return 0;
}
