// Problem Link: https://codeforces.com/problemset/problem/1285/B
// Solution Link: https://www.youtube.com/watch?v=5_2Edsf-gSo

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll find(int i, int n, vector<int>& v){
    ll sum = v[i], curr = 0;
    for(;i<n;i++){
        curr += v[i];

        sum = max(sum, curr);

        if(curr < 0)    curr = 0;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        ll sum = 0;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
            sum += v[i];
        }

        if(n == 1){
            cout<<"NO\n";
            continue;
        }

        ll x = find(0,n-1,v);
        ll y = find(1, n, v);

        if(sum > max(x,y))  cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    return 0;
}
