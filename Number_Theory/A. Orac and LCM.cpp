// Problem Link: https://codeforces.com/problemset/problem/1349/A
// Solution Link: https://www.youtube.com/watch?v=aAWeBFzqSYM


/*
  Hint : 
    let say we have two number 10 and 15.
    so, there prime factoriztion is:
    10 -> 2^1  *  3^0  *  5^0
    15 -> 2^0  *  3^1  *  5^1

    lcm -> 2^1  *  3^1  *  5^1    (largest power of all prime factors) 
    gcd -> 2^0  *  3^0  *  5^1    (smalles power of all prime factors)
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

    int N = 200001;
    vector<int> spf(N, 1e9);

    for(int i = 2; i<N; i++){
        if(spf[i] != (int)1e9)  continue;
        for(int j = i; j<N; j+=i)   spf[j] = min(spf[j], i);
    }

    int n;
    cin>>n;

    vector<ll> v(n);
    map<ll,vector<ll>> mp;

    for(int i=0; i<n; i++){
        cin>>v[i];

        int x = v[i];
        while(x != 1){
            int fact = spf[x], count = 0;
            while(x%fact == 0){
                x /= fact;
                count++;
            }
            mp[fact].push_back(count);
        }
    }

    ll ans = 1;

    for(auto& [x,y]:mp){
        sort(y.begin(),y.end());
        int sz = y.size();
        if(sz == n) ans = ans * 1ll * pow(x, y[1]);
        else if(sz == n-1)  ans = ans * 1ll * pow(x, y[0]);
    }
    cout<<ans<<endl;

    return 0;
}
