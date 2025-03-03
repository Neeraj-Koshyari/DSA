// Priblem Link: https://cses.fi/problemset/task/1733/
// Solution Link: https://www.youtube.com/watch?v=sS6m2SN3K9M

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> z_function(string &s, int n){
    vector<int> z(n);
    int l=0,r=0;
    for(int i=1; i<n; i++){
        if(r > i)   z[i] = min(r-i, z[i-l]);

        while (i+z[i] < n && s[z[i]] == s[i+z[i]])  z[i]++;

        if(i+z[i] > r){
            r = i+z[i];
            l = i;
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
    vector<int> z = z_function(s,n);

    for(int i=1; i<n; i++){
        if(z[i] == n-i) cout<<i<<" ";
    }
    cout<<n<<endl;
    return 0;
}
