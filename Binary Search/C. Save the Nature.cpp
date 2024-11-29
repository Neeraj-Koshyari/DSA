// Problem Link: https://codeforces.com/problemset/problem/1223/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool ok(ll size, vector<ll>& v, ll x, ll a, ll y, ll b, ll x_y, ll k){
	ll n = size / a, m = size / b, both = size / x_y, sum = 0;
	n -= both;
	m -= both;

	for(int idx = 0; idx < size; idx++){
		if(both != 0){
			sum += (v[idx] / 100 * (x + y));
			both--;
		}
		else if(m != 0){
			sum += (v[idx] / 100 * y);
			m--;
		}
		else if(n != 0){
			sum += (v[idx] / 100 * x);
			n--;
		}
		else break;
	}
	return sum >= k;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;

	while(t--){
		ll n;
		cin>>n;

		vector<ll> v(n);
		for(int i=0;i<n;i++)	cin>>v[i];

		ll x,a,y,b,k;
		cin>>x>>a>>y>>b>>k;

		if(x > y){
			swap(x,y);
			swap(a,b);
		}

		sort(v.rbegin(), v.rend());
		ll l = -1, r = n, x_y = (a * b / gcd(a,b));

		while(l+1 < r){
			ll mid = (l+r)/2;

			if(ok(mid+1, v, x, a, y, b, x_y, k))	r = mid;
			else l = mid;
		}
		
		if(r == n)	cout<<-1<<endl;
		else cout<<r+1<<endl;
	}
	return 0;
}
