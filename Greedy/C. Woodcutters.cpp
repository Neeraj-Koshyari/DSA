// Problem Link: https://codeforces.com/problemset/problem/545/C
// Solution Link: https://www.youtube.com/watch?v=bqJvaMtMO1k

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 2;
    cin>>n;

    vector<pair<int,int>> v(n);
    for(int i=0; i<n; i++) cin>>v[i].first>>v[i].second;

    if(n == 1){
        cout<<1<<endl;
        return 0;
    }

    sort(v.begin(), v.end());

    for(int i=1;i<n-1;i++){
        if(v[i].first - v[i].second > v[i-1].first) ans++;
        else if(v[i].first + v[i].second < v[i+1].first){
            ans++;
            v[i].first += v[i].second;
        }
    }
    cout<<ans<<endl;
    return 0;
}
