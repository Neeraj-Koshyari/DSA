// Problem Link: https://codeforces.com/problemset/problem/1765/N
// Solution Link: https://www.youtube.com/watch?v=YcSnMgm4Be4

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void find(int i, int k, int& mn_idx, int n, vector<deque<int>>& v){
    for(;i<=10;i++){
        while(v[i].size() && v[i].front() < mn_idx)    v[i].pop_front();

        if(v[i].size() && (n-v[i].front()) >= k){
            cout<<i;
            mn_idx = v[i].front();
            v[i].pop_front();
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        string s;
        ll k;

        cin>>s>>k;

        ll n = s.length();
        k = n-k;

        vector<deque<int>> v(10);
        for(int i=0;i<n;i++)    v[s[i]-'0'].push_back(i);

        int mn = 10, mn_idx = -1;
        find(1,k,mn_idx,n,v);
        while(--k){
            find(0,k,mn_idx,n,v);
        }
        cout<<endl;
    }
    
    return 0;
}
