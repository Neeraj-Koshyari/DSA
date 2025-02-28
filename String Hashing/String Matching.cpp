// Problem Link: https://cses.fi/problemset/task/1753/
// Solution Link: https://www.youtube.com/watch?v=rQ5aNVeVKcg

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> z_function(string& s, int n){
    int l = 0, r = 0;
    vector<int> z(n,0);
    for(int i=1;i<n;i++){
        if(i < r)    z[i] = min(r - i, z[i-l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])   z[i]++;

        if(i + z[i] > r){
            r = i + z[i];
            l = i;
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a,b;
    cin>>a>>b;

    string s = b + "$" + a;
    int n = s.length();

    vector<int> z = z_function(s,n);

    int m = b.size(), count = 0;

    for(int i = m; i<n; i++){
        if(z[i] == m)   count++;
    }
    cout<<count<<endl;
    
    return 0;
}
