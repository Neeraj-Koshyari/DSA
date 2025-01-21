// Problem Link: https://codeforces.com/problemset/problem/312/B
// Solution Link: https://www.youtube.com/watch?v=8lt0PmuVids


/*
  try to make a formula
  */

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout<<fixed<<setprecision(10);

    double a,b,c,d;
    cin>>a>>b>>c>>d;

    double ans = ((a*d) / (b*c + a*d - a*c));
    cout<<ans<<endl;
    
    return 0;
}
