// Problem Link: https://cses.fi/problemset/task/1164
// Solution Link: https://www.youtube.com/watch?v=4B1RWApyfjc

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin>>n;
 
    vector<pair<pair<int,int>, int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first.first>>v[i].first.second;
        v[i].second = i;
    }
 
    sort(v.begin(),v.end());
 
    set<pair<int,int>> st;
    vector<int> ans(n);
    st.insert({v[0].first.second, v[0].second});
 
    ans[v[0].second] = 1;
    int mx = 1;
 
    for(int i=1;i<n;i++){
        auto node = *st.begin();
        int end = node.first;
        int idx = node.second;
 
        int curr_start = v[i].first.first;
        int curr_end = v[i].first.second;
        int curr_idx = v[i].second;
 
        if(curr_start > end){
            st.erase(st.begin());
            ans[curr_idx] = ans[idx];
        }
        else{
            mx++;
            ans[curr_idx] = mx;
        }
        st.insert({curr_end, curr_idx});
    }
 
    cout<<mx<<endl;
    for(int i=0;i<n;i++)    cout<<ans[i]<<" ";
 
    return 0;
}
