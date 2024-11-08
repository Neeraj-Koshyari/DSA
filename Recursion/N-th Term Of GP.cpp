// Problem Link : https://www.naukri.com/code360/problems/nth-term-of-gp_797999

const int mod = 1e9+7;

int pow(int x, int y){
    int ans = 1;
    while(y){
        if(y&1) ans = (ans * 1ll * x) % mod;

        x = (x * 1ll * x) % mod;
        y/=2;
    }
    return ans;
}

int nthTermOfGP(int N, int A, int R) {
    // Write your code here.
    return (A * 1ll * pow(R,N-1)) % mod;
}
