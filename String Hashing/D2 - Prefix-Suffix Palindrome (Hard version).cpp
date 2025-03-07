// Problem Link: 

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string find_pallin(string& a){
    string s = a;
    reverse(s.begin(), s.end());
    s = a + "#" + s;

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

    int len = 0;
    for(int i=1;i<n;i++){
        if(z[i] == n-i){
            len = z[i];
            break;
        }
    }
    return s.substr(0,len);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        string a;
        cin>>a;

        int idx = 0, n = a.size();

        while(idx < n && a[idx] == a[n-1-idx])  idx++;

        if(idx == n){
            cout<<a<<endl;
            continue;
        }
        
        cout<<a.substr(0,idx);

        string s = a.substr(idx, n-2*idx);
        string x = find_pallin(s);    // find pallindrom with remaining substring which is a prefix
        reverse(s.begin(),s.end());
        string y = find_pallin(s);

        if((int)x.size() >= (int)y.size())   cout<<x;
        else cout<<y;

        cout<<a.substr(n-idx, idx)<<endl;
    }

    return 0;
}
