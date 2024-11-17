// Problem Link : https://cses.fi/problemset/task/2422
// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
bool ok(ll x, ll k, ll n){
	ll count = 0;
	for(int i=1;i<=n;i++){
		count += min(n,(x/i));
	}
	return count < k;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n;
	cin>>n;
 
	ll l = 1, r = n*n, k = (n*n + 1)/2;
	while(l+1 < r){
		ll mid = (l+r)/2;
 
		if(ok(mid,k,n))	l = mid;
		else r = mid;
	}
	cout<<r<<endl;
 
    return 0;
}
