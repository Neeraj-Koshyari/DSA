//this algo find the power of 'x' with some mod 'M' in O ( log (n) ) time complexity

long long int PowMod(long long int x,long long int n,long long int M){
    long long int ans = 1;
    while(n){
        if(n&1){
            ans = (ans * x)%M;
        }
        x = (x*x)%M;
        n/=2;
    }
    return ans;
}
