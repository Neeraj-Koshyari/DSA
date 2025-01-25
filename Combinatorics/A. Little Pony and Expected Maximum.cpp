// Problem Link: https://codeforces.com/problemset/problem/453/A
// Solution Link: https://www.youtube.com/watch?v=L0Ie4qLNouk


/*
  Hint: insted of finding ( i^m - (i-1)^m ) / (n^m) where 0 < i <= n
    we can find ( i/n )^m - ( (i-1)/n )^m
  */

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

double power(double x, ll y){
    double ans = 1;
    while(y){
        if(y&1) ans = (ans * x);
        x *= x;
        y /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout<<fixed<<setprecision(15);

    ll n,m, mod = 1e9+7;
    cin>>n>>m;

    double ans = 0;

    vector<double> v(n+1);
    for(int i=1;i<=n;i++){
        double val = i/(double)n;
        v[i] = power(val,m);

        ans += ((v[i] - v[i-1]) * (double)i);
    }
    cout<<ans<<endl;

    return 0;
}
