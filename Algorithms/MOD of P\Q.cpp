// NOTE: Q ^ -1  ->  Q power -1

// For Finding  ( P / Q ) % MOD we have to find ( P *  ( Q ^ -1 ) ) % MOD
// So, for finding MOD of Q inverse ( Q ^ -1 ) we can do ( Q ^ ( MOD - 2 ) ) % MOD. By this we will find Q inverse

// code : 
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

int main(){
  int P, Q, MOD = 1e9+7;
  cin>>P>>Q;

  int Q_inverse = PowMod(Q, MOD-2, MOD);
  int ans = ( P * Q_inverse ) % MOD;
  
  cout<<ans<<endl;
}
