//  solve the problem: (fact(x) / fact(y)) % MOD

const int MAX = 1000005;
const int MOD = 1e9 + 7;

long long fact[MAX], invFact[MAX];

// Binary exponentiation function
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Modular inverse of a single number
long long modInverse(long long n) {
    return power(n, MOD - 2);
}

// Precompute factorials and inverse factorials
void precompute() {
    fact[0] = invFact[0] = 1;
    long long prev = 1;
    
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    
    // Compute inverse of the largest factorial using Fermat's Little Theorem
    invFact[MAX - 1] = modInverse(fact[MAX - 1]);
    
    // Backtrack to find remaining inverse factorials in O(n)
    for (int i = MAX - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}
