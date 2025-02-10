// Problem Link: https://cses.fi/problemset/task/1073
// Solution Link: https://www.youtube.com/watch?v=2swjxPlRzD8

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

    multiset<int> st;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        auto it = st.upper_bound(x);

        if(it != st.end())  st.erase(it);
        st.insert(x);
    }
    cout<<(int)st.size()<<endl;;
    
    return 0;
}
