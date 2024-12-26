// Problem Link: https://codeforces.com/gym/101628/problem/J

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool ok(ll pile_sz, vector<vector<ll>>& piles, ll total_cost){
	ll cost = 0, count = 0;
	vector<pair<ll,ll>> less_piles;
	for(auto& x : piles){
		if(x[0] > pile_sz){
			cost += ((x[0]-pile_sz) * x[1]);
			count += (x[0]-pile_sz);
		}
		else if(x[0] < pile_sz)	less_piles.push_back({x[2],x[0]});
	}

	sort(less_piles.begin(),less_piles.end());
	for(auto& x : less_piles){
		ll rem = min(pile_sz - x.second, count);
		count -= rem;
		cost += (rem * x.first);
		if(cost > total_cost)	return false;
	}

	return count <= 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n,k;
	cin>>n>>k;

	vector<vector<ll>> v(n,vector<ll>(3));
	for(int i=0;i<n;i++)	cin>>v[i][0]>>v[i][1]>>v[i][2];

	ll l = 0, r = 1e18+1;
	while(l+1 < r){
		ll mid = (l+r)/2;

		if(ok(mid,v,k))	r = mid;
		else l = mid;
	}
	cout<<r<<endl;

	return 0;
}
