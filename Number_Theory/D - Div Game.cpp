// Problem Link: https://atcoder.jp/contests/abc169/tasks/abc169_d
// Solution Link: https://www.youtube.com/watch?v=AqRiFCiNN5s

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll find(ll val){
    ll a = 1, b = val;

    while(a+1 < b){
        ll mid = (a+b)/2;

        if((mid * (mid+1))/2 <= val)    a = mid;
        else b = mid;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin>>n;

    vector<ll> factor;

    for(ll i=2; i*i<=n; i++){
        ll count = 0;
        while(n%i == 0){
            n /= i;
            count++;
        }
        if(count > 0)  factor.push_back(count);
    }
    if(n > 1)   factor.push_back(1);
    
    ll ans = 0;
    for(auto& x: factor){
        ans += find(x);
    }
    cout<<ans<<endl;

    return 0;
}
