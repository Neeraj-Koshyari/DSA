// Problem Link: https://codeforces.com/problemset/problem/1990/D

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
        int n;
        cin>>n;

        vector<int> v(n);
        for(int i=0;i<n;i++)    cin>>v[i];

        int ans = 0, b1 = 0, b2 = 0;
        for(int i=0;i<n;i++){
            if(b1 == 0 && b2 == 0){
                if(v[i] == 0)   continue;
                ans++;
                if(v[i] <= 2)   b1 = 1;
            }
            else if(b1){
                b1 = 0;
                if(v[i] <= 2)   continue;
                ans++;
                if(v[i] <= 4)   b2 = 1;
            }
            else{
                b2 = 0;
                if(v[i] == 0)   continue;
                ans++;
                if(v[i] <= 4)   b1 = 1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
