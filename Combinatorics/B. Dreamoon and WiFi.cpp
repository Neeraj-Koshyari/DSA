// Problem Link: https://codeforces.com/problemset/problem/476/B
// Solution Link: https://www.youtube.com/watch?v=l_NhIm0JhXg

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<double> fact(11);
    fact[0] = fact[1] = 1;
    for(int i=2;i<11;i++)   fact[i] = fact[i-1] * (double)i;

    string s,t;
    cin>>s>>t;

    int n = s.length();
    double ans = 0, pos = 0, neg = 0, unknown = 1, total_outcome = 1;
    for(int i=0;i<n;i++){
        if(s[i] == '+') pos++;
        else neg++;

        if(t[i] == '?') total_outcome *= 2;
        else if(t[i] == '+')    pos--;
        else neg--;
    }

    cout<<fixed<<setprecision(10);

    if(pos < 0 || neg < 0)  cout<<ans<<endl;
    else{
        double val = min(pos, neg), total = pos + neg;
        ans = fact[total] / (fact[val] * fact[total - val]);
        ans = ans/total_outcome;
        cout<<ans<<endl;
    }
    
    return 0;
}
