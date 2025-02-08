// Problem Link: https://codeforces.com/problemset/problem/922/D

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
    
    vector<string> v(n);
    for(int i=0;i<n;i++)    cin>>v[i];

    auto f = [](string s) -> ll{
        ll count = 0, ans = 0;
        for(auto& x : s){
            if(x == 's') count++;
            else ans += count;
        }
        return ans;
    };

    sort(v.begin(), v.end(), [&](string& s, string& t){
        return f(s + t) > f(t + s);
    });

    string s;
    for(int i=0;i<n;i++)    s += v[i];

    cout<<f(s)<<endl;
    
    return 0;
}
