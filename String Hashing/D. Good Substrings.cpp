// Problem Link: https://codeforces.com/contest/271/problem/D
// Solution Link: https://www.youtube.com/watch?v=52Jd_JCP2ao

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    string s,badness;
    cin>>s>>badness>>k;

    int n = s.length();
    vector<ll> v(n);
    v[0] = 1 - (badness[(s[0]-'a')] - '0');
    for(int i=1; i<n; i++)
        v[i] += (v[i-1] + 1 - (badness[(s[i]-'a')] - '0'));
    

    Hashing obj(s);
    vector<vector<ll>> allHashCode;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            ll num1 = v[j], num2 = 0;
            if(i>0) num2 = v[i-1];

            if((num1 - num2) > k)   continue;

            vector<ll> temp = obj.hashCode(i,j);
            allHashCode.push_back(temp);
        }
    }

    sort(allHashCode.begin(), allHashCode.end());

    ll ans = 0, m = allHashCode.size();
    for(int i=1; i<m; i++){
        if(allHashCode[i] != allHashCode[i-1])  ans++;
    }
    if(m > 0)   ans++;
    
    cout<<ans<<endl;
    return 0;
}
