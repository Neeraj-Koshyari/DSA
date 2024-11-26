// Problem Link: https://codeforces.com/problemset/problem/1487/D

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll N = 2e5, ans = 0;
	vector<ll> v;

	for(ll a=3; a<N; a+=2){
		ll b = a*a / 2;
		ll c = b + 1;

		if(a <= b && b <= c && (a*a - b) == c)	v.push_back(c);
	}
	
	int t;
	cin>>t;

	while(t--){
		ll n;
		cin>>n;
		ll ans = upper_bound(v.begin(),v.end(), n) - v.begin();
		cout<<ans<<endl;
	}
    return 0;
}
