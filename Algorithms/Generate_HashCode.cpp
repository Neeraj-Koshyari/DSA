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
    ll primes, base = 239017, n;

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
