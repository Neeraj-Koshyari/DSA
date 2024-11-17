// Problem Link : https://cses.fi/problemset/task/1620

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
bool ok(ll t, vector<ll>& v, ll k){
	ll total_products = 0;
	for(auto& x:v){
		total_products += (t/x);
	}
	if(total_products >= k)	return true;
	return false;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n,p;
	cin>>n>>p;
 
	vector<ll> v(n);
	for(int i=0;i<n;i++)	cin>>v[i];
 
	ll l = 0, r = 1;
	while(!ok(r,v,p)){
		l = r;
		r = r*2;
	}
 
	while(l+1 < r){
		ll mid = (l+r)/2;
 
		if(ok(mid,v,p))	r = mid;
		else l = mid;
	}
 
	cout<<r<<endl;
 
    return 0;
}
