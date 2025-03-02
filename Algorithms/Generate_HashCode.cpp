#define ll long long int

class Hashing{
    private:
    ll invMult(ll x, ll y, ll mod){
        ll res = 1;
        while(y){
            if(y&1) res = (res * x)%mod;

            x = (x*x)%mod;
            y /= 2;
        }
        return res;
    }

    public:
    string s;
    int n;
    int primes;
    vector<ll> hashPrimes = {1000000007, 1000000009};
    const ll base = 31;

    vector<vector<ll>> hashValues, pBase, invPBase;
    Hashing(string& a){
        s = a;
        n = s.length();
        primes = hashPrimes.size();
        hashValues.resize(primes, vector<ll>(n));
        pBase.resize(primes, vector<ll>(n+1));
        invPBase.resize(primes, vector<ll>(n+1));

        for(int i=0; i<primes; i++){
            pBase[i][0] = 1;
            for(int j=1; j<=n; j++){
                pBase[i][j] = (pBase[i][j-1] * base)%hashPrimes[i];
            }

            invPBase[i][n] = invMult(pBase[i][n], hashPrimes[i] - 2, hashPrimes[i]);
            for(int j=n-1; j>=0; j--){
                invPBase[i][j] = (invPBase[i][j+1] * base)%hashPrimes[i];
            }
        }

        for(int i=0; i<primes; i++){
            for(int j=0; j<n; j++){
                hashValues[i][j] = ((s[j]-'a' + 1ll) * pBase[i][j]) % hashPrimes[i];
                if(j>0)
                    hashValues[i][j] = (hashValues[i][j] + hashValues[i][j-1]) % hashPrimes[i];
            }
        }
    }
    vector<ll> hashCode(int l, int r){
        vector<ll> hash(primes);
        for(int i=0; i<primes; i++){
            ll num1 = hashValues[i][r];
            ll num2 = 0;

            if(l > 0)   num2 = hashValues[i][l-1];

            hash[i] = ((num1 - num2 + hashPrimes[i]) % hashPrimes[i]);
            hash[i] = (hash[i] * invPBase[i][l])%hashPrimes[i];
        }
        return hash;
    }
};
