// Problem Link: https://codeforces.com/problemset/problem/1010/B

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int Ask(int x){
	cout<<x<<endl;
	cin>>x;

	if(x == 0)	exit(0);
	return x;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m,n;
	cin>>m>>n;

	vector<int> v(n);
	for(int i=1;i<=n;i++){
		v[i-1] = Ask(i);
	}

	ll l = 1, r = m+1, idx = 0;
	while(l+1 < r){
		ll mid = (l+r)/2;

		int val = Ask(mid);
		if(v[idx] == 1){
			if(val == 1)	l = mid;
			else r = mid;
		}
		else{
			if(val == -1)	l = mid;
			else r = mid;
		}
		idx = (idx+1)%n;
	}
	
	return 0;
}
