// Problem Link: https://codeforces.com/problemset/problem/1833/F
// Solution Link: https://www.youtube.com/watch?v=LZDgz0xKIpg

/*
  observation:
    the answer window will me 'm' consecutive number
    ex: 
    let, m = 3, n = 5
    1 2 3 4 5
    the aswer is frequency of ( 1 * 2 * 3 ) + ( 2 * 3 * 4 ) + ( 3 * 4 * 5 )
*/
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll power(ll x, ll y, ll mod){
	ll ans = 1;

	while(y){
		if(y&1)	ans = (ans*x)%mod;

		x = (x*x)%mod;
		y /= 2;
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	
	while(t--){
		int n,m;
		cin>>n>>m;

		map<int,ll> mp;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			mp[x]++;
		}

		vector<int> v;
		for(auto& x:mp)	v.push_back(x.first);

		n = v.size();

		if(m > n){
			cout<<0<<endl;
			continue;
		}

		ll ans = 0, product = 1, mod = 1e9+7;
		for(int i=0;i<m;i++)	product = (product * 1ll * mp[v[i]])%mod;

		ans = ((v[m-1] - v[0]) == m-1)? product:0;
		for(int i=m;i<n;i++){
			ll mod_inv = power(mp[v[i-m]], mod-2, mod);

			product = (product * 1ll * mod_inv)%mod;
			product = (product * 1ll * mp[v[i]])%mod;

			if(v[i] - v[i-m+1] == m-1)	ans = (ans + product)%mod;
		}
		cout<<ans<<endl;
	}

	return 0;
}
