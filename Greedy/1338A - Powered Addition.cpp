// Problem Link: https://codeforces.com/problemset/problem/1338/A
// Solition Link: https://www.youtube.com/watch?v=QF0fMG3zQ3c

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

char find(string& s, int n){
    char mx = 'a';
    for(int i=0;i<n;i++){
        mx = max(mx, s[i]);
    }

    return mx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<ll> v(n);
        for(int i=0; i<n; i++)  cin>>v[i];

        ll count = 0, sum = 0;
        for(int i=1; i<n; i++){
            if(v[i] >= v[i-1])  continue;

            while((v[i] + sum) < v[i-1]){
                sum += (1<<count);
                count++;
            }

            v[i] = v[i-1];
        }
        cout<<count<<endl;
    }
       
    return 0;
}
