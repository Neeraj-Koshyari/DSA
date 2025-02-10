// Problem Link: https://cses.fi/problemset/task/2183
// Solution Link: https://www.youtube.com/watch?v=M4ZgbGPvSRg

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

    vector<int> v(n);
    for(int i=0;i<n;i++)    cin>>v[i];

    sort(v.begin(), v.end());

    ll sum = 0;
    for(int i=0;i<n;i++){
        if(v[i] > (sum+1))  break;
        
        sum += v[i];
    }
    cout<<sum+1<<endl;
    
    return 0;
}
