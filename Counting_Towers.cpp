// Problem Link: https://cses.fi/problemset/task/2413

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	int N=1e6+1;
	vector<ll> dp(N);
	dp[1] = 2;
	ll prev0 = 1, prev1 = 1, mod = 1e9+7;
	for(int i=2;i<N;i++){
		ll curr0 = ((4ll * prev0)%mod + prev1)%mod;
		ll curr1 = ((2ll * prev1)%mod + prev0)%mod;
		prev0 = curr0;
		prev1 = curr1;
		dp[i] = (prev0 + prev1)%mod;
	}

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<dp[n]<<endl;
	}
	return 0;
}
