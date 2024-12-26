// Problem Link: https://cses.fi/problemset/task/1641
// Youtube Link: https://www.youtube.com/watch?v=H4KPwVDP_h8

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void sol(){
	ll n,x;
	cin>>n>>x;

	vector<pair<ll,int>> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].first;
		v[i].second = i+1;
	}

	sort(v.begin(),v.end());

	for(int i=0;i<n-2;i++){
		int l = i+1, r = n-1;
		while(l<r){
			ll sum = v[i].first + v[l].first + v[r].first;
			if(sum == x){
				cout<<v[i].second<<" "<<v[l].second<<" "<<v[r].second;
				return;
			}
			
			if(sum < x)	l++;
			else r--;
		}
	}
	cout<<"IMPOSSIBLE";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	sol();

	return 0;
}
