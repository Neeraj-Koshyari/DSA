// Problem Link: https://codeforces.com/problemset/problem/126/B
// Solution Link: https://www.youtube.com/watch?v=Bwa-k7emtgY

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> z_function(string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;

    int n = s.length();

    if(n < 3){
        cout<<"Just a legend\n";
        return 0;
    }

    vector<int> z = z_function(s);

    int len = 0, last = 0;
    for(int i = n-1; i>0; i--){
        if(z[i] >= last){
            len = last;
            if(z[i] == n-i) last = z[i];
        }
    }

    if(len == 0)    cout<<"Just a legend\n";
    else cout<<s.substr(0,len)<<endl;

    return 0;
}
