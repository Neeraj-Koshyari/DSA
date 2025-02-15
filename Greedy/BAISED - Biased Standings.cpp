// Problem Link: https://www.spoj.com/problems/BAISED/
// Solution Link: https://www.youtube.com/watch?v=hmSzjHqK5Pc

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        ll n, sum = 0;
        cin>>n;

        vector<ll> v(n);
        for(int i=0;i<n;i++){
            string s;
            cin>>s>>v[i];
        }

        sort(v.begin(),v.end());
        for(ll i = 1; i<=n; i++)    sum += abs(v[i-1] - i);

        cout<<sum<<endl;
    }
    
    return 0;
}
