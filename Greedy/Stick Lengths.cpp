// Problem Link: https://cses.fi/problemset/task/1074
// Solution Link: https://www.youtube.com/watch?v=pGUIsBpmQ8o

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
 
    vector<int> v(n);
    for(int i=0;i<n;i++)    cin>>v[i];
 
    sort(v.begin(),v.end());
 
    ll mid = v[n/2], ans = 0;
    for(int i=0;i<n;i++)    ans += abs(v[i] - mid);
 
    cout<<ans<<endl;
 
    return 0;
}
