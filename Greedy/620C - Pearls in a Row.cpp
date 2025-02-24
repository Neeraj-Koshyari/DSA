// Problem Link: https://codeforces.com/problemset/problem/620/C
// Solution Link: https://www.youtube.com/watch?v=w-ELOttI-78

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, last_idx = 0;
    cin>>n;

    map<int,int> mp;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        if(mp[x] != 0 && mp[x] > last_idx){
            v.push_back({last_idx+1,i+1});
            last_idx = i+1;
            mp[x] = 0;
        }
        else    mp[x] = i+1;
    }

    int m = v.size();

    if(m == 0)  cout<<-1<<endl;
    else{
        cout<<m<<endl;
        for(int i=0;i<m-1;i++)  cout<<v[i].first<<" "<<v[i].second<<endl;
        cout<<v[m-1].first<<" "<<n<<endl;
    }
    
    return 0;
}
