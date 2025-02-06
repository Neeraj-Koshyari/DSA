// Problem Link: https://codeforces.com/problemset/problem/1791/G1
// Solution Link: https://www.youtube.com/watch?v=FlAU830Hjf8

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
        int n, k;
        cin>>n>>k;

        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            v[i] += (i+1);
        }

        sort(v.begin(),v.end());

        int ans = 0;
        for(int i=0;i<n;i++){
            if(k < v[i])    break;
            k -= v[i];
            ans++;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
