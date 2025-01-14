// Problem Link: https://codeforces.com/contest/876/problem/B
// Solution Link: https://www.youtube.com/watch?v=WrVA9WjMToQ

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k,m,mx = 0, val = 0;
    cin>>n>>k>>m;

    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        mp[x%m].push_back(x);
        int sz = mp[x%m].size();
        if(sz > mx){
            mx = sz;
            val = x%m;
        }
    }

    if(mx < k)  cout<<"No";
    else{
        cout<<"Yes\n";
        for(int i=0;i<k;i++)    cout<<mp[val][i]<<" ";
    }
    cout<<endl;

    return 0;
}
