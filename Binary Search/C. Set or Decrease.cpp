// Problem Link: https://codeforces.com/problemset/problem/1622/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool ok(ll x, vector<ll>& v, ll k){
	ll n = v.size();

	ll m = min(n-1, x), sum = 0;
	for(int i=1; i<n-m; i++)	sum += v[i];

	for(int i=n-m; i<n; i++){
		ll total = (m+1) * (v[0] - (x-m)) + sum;
		if(total <= k)	return true;
		
		sum += v[i];
		m--;
	}

	ll total = (m+1) * (v[0] - (x-m)) + sum;
	if(total <= k)	return true;
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;

	while(t--){
		ll n,k;
		cin>>n>>k;

		vector<ll> v(n);
		for(int i=0;i<n;i++)	cin>>v[i];

		sort(v.begin(),v.end());

		ll l = -1, r = 1e16;
		while(l+1 < r){
			ll mid = (l+r)/2;

			if(ok(mid,v,k))	r = mid;
			else l = mid;
		}
		cout<<r<<endl;
	}

	return 0;
}
