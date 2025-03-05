// Problem Link: https://codeforces.com/problemset/problem/979/B

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll find(string& s, ll n, ll op){
    map<char,ll> mp;
    ll mx = 0;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
        mx = max(mx, mp[s[i]]);
    }

    if(op == 1 && mx == n)  return n-1;

    return min(mx+op, n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin>>n;

    string a,b,c;
    cin>>a>>b>>c;

    ll m = a.length();

    ll mx1 = find(a,m,n);
    ll mx2 = find(b,m,n);
    ll mx3 = find(c,m,n);

    if(mx1 > mx2 && mx1 > mx3)  cout<<"Kuro\n";
    else if(mx2 > mx1 && mx2 > mx3) cout<<"Shiro\n";
    else if(mx3 > mx1 && mx3 > mx2) cout<<"Katie\n";
    else cout<<"Draw\n";

    return 0;
}
