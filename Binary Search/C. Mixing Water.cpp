// Problem Link: https://codeforces.com/problemset/problem/1359/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll find(ll val, ll h, ll c){
	ll left = (val+1) * h;
	ll right = val * c;

	return (left + right);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;

	while(t--){
		ll c,h,t;
		cin>>h>>c>>t;

		if((2*t) <= (h+c)){
			cout<<2<<endl;
			continue;
		}

		ll l = 0, r = 1e8+1;
		while(l+1<r){
			ll mid = (l+r)/2;

			if(find(mid,h,c) > (t*(2*mid+1)))	l = mid;
			else r = mid;
		}

		double c1 = abs(t - ((l+1)*h + l*c)/(2.0*l + 1));
		double c2 = abs(t - ((r+1)*h + r*c)/(2.0*r + 1));

		if(c1 <= c2)	cout<<2*l+1<<endl;
		else cout<<2*r+1<<endl;
	}
	
	return 0;
}
