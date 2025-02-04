// Problem Link: https://cses.fi/problemset/task/1632
// Solution Link: https://www.youtube.com/watch?v=SIXQ9Zav9H8

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k; 
    cin>>n>>k;

    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)    cin>>v[i].first>>v[i].second;

    sort(v.begin(),v.end(), [&](auto& x, auto& y){
        if(x.second == y.second)    return x.first < y.first;
        return x.second < y.second;
    });

    int ans = 0;
    multiset<int> st;
    for(int i=0;i<k;i++)    st.insert(-1);

    for(auto& x : v){
        auto it = st.upper_bound(x.first);
        if(it == st.begin())  continue;

        st.erase(--it);
        st.insert(x.second);
        ans++;
    }
    cout<<ans<<endl;

    return 0;
}
