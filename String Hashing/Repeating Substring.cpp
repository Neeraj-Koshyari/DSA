// Problem Link: https://cses.fi/problemset/task/2106
// Solution Link: https://www.youtube.com/watch?v=2ojQCkjoP6U

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Hashing{
    private:
    ll modPower(ll x, ll y, ll mod){
        ll res = 1;

        while(y){
            if(y)   res = (res * x) % mod;

            x = (x * x) % mod;
            y /= 2;
        }
        return res;
    }

    public:
    string s;
    ll primes, base = 31, n;

    vector<ll> hashPrimes = {1000000009, 1000000007};
    vector<vector<ll>> hashValues, baseP, baseInvP;

    Hashing(string &a){
        s = a;
        n = s.length();
        primes = hashPrimes.size();

        hashValues.resize(primes, vector<ll>(n));
        baseP.resize(primes, vector<ll>(n));
        baseInvP.resize(primes, vector<ll>(n));

        for(int i=0; i<primes; i++){
            baseP[i][0] = 1;
            for(int j=1; j<n; j++)
                baseP[i][j] = (baseP[i][j-1] * base) % hashPrimes[i];

            baseInvP[i][n-1] = modPower(baseP[i][n-1], hashPrimes[i]-2, hashPrimes[i]);
            for(int j=n-2; j>=0; j--)
                baseInvP[i][j] = (baseInvP[i][j+1] * base) % hashPrimes[i];
        }

        for(int i=0; i<primes; i++){
            for(int j=0; j<n; j++){
                hashValues[i][j] = ((s[j] - 'a' + 1ll) * baseP[i][j]) % hashPrimes[i];

                if(j>0) hashValues[i][j] = (hashValues[i][j] + hashValues[i][j-1]) % hashPrimes[i];
            }
        }
    }

    vector<ll> hashCode(int l, int r){
        vector<ll> code(primes);
        for(int i=0; i<primes; i++){
            ll num1 = hashValues[i][r], num2 = 0;

            if(l > 0)   num2 = hashValues[i][l-1];

            code[i] = ((num1 - num2 + hashPrimes[i])%hashPrimes[i] * baseInvP[i][l]) % hashPrimes[i];
        }
        return code;
    }
};

int ok(Hashing &obj, int len, string& s, int n){
    unordered_set<ll> st;
    for(int i=0; i<=(n-len); i++){
        vector<ll> temp = obj.hashCode(i, i+len-1);
        ll val = temp[0] * 1000000021 + temp[1];
        if(st.count(val))  return i;
        st.insert(val);
    }
    return - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;

    int n = s.length();
    Hashing obj(s);

    int l = 0, r = n, idx = -1;
    while(l+1 < r){
        int mid = (l+r)/2;

        int id = ok(obj, mid, s, n);
        if(id != -1){  
            l = mid;
            idx = id;
        }
        else r = mid;
    }

    if(l == 0)  cout<<-1<<endl;
    else cout<<s.substr(idx, l)<<endl;

    return 0;
}
