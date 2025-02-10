// Problem Link: https://codeforces.com/problemset/problem/1810/C
// Solution Link: https://www.youtube.com/watch?v=tRkiDMUDFNk

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
        ll n,c,d, flag = 0;
        cin>>n>>c>>d;

        set<ll> st;
        vector<ll> v;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            st.insert(x);

            if(x == 1)  flag = 1;
        }

        if(flag == 0)   v.push_back(1);
        for(auto x:st) v.push_back(x);

        int m = v.size();

        ll ans = 0, val = 1, mn = 1e15;
        if(flag)    ans = (n-m)* 1ll *c;
        else ans = d + (n - m + 1)* 1ll *c;

        for(int i=0;i<m;i++){
            if(v[i] != val){
                ll val1 = (m-i)* 1ll *c;
                ll val2 = (v[i] - val)* 1ll *d;

                if(val1 <= val2){   
                    ans += val1;
                    break;
                }

                mn = min(mn, ans + val1);

                ans += val2;
                val = v[i] + 1;
            }
            else val++;
        }
        cout<<min(ans,mn)<<endl;
    }
    
    return 0;
}
