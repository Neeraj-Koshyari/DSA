// Problem Link: https://codeforces.com/problemset/problem/1623/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool ok(int x, vector<int> v){
	int n = v.size();
	vector<int> shared(n);

	for(int i = n-3; i >= 0; i--){
		int val = v[i+2] + shared[i+2];
		int extra = min(val - x, v[i+2]);
		int d = extra/3;

		if(d < 1)	continue;

		v[i+2] -= 3*d;
		shared[i+1] += d;
		shared[i] += 2*d;
	}

	for(int i=0; i<n; i++){
		int val = v[i] + shared[i];
		if(val < x)	return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<int> v(n);
		for(int i=0;i<n;i++)	cin>>v[i];

		if(n<3){
			if(n==1)	cout<<v[0]<<endl;
			else cout<<min(v[0],v[1])<<endl;
			continue;
		}

		int l = 0, r = v[n-1]+1;
		while(l+1 < r){
			int mid = (l+r)/2;

			if(ok(mid,v))	l = mid;
			else r = mid;
		}
		cout<<l<<endl;
	}

	return 0;
}
