// Problem Link: https://codeforces.com/problemset/problem/1479/A

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int Ask(int x, int n, vector<int>& v){
	if(x == 0 || x == n+1)	return 1e9;
	if(v[x] != -1)	return v[x];

	cout<<"? "<<x<<endl;
	cin>>v[x];

	return v[x];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;

	vector<int> v(n+1,-1);
	int l = 1, r = n;

	while(l < r){
		int mid = (l+r)/2;

		int a = Ask(mid-1,n,v);
		int b = Ask(mid,n,v);
		int c = Ask(mid+1,n,v);

		if(b < min(a,c)){
			l = mid;
			r = mid;
			break;
		}
		else if(a < b)	r = mid - 1;
		else l = mid + 1;
	}
	cout<<"! "<<r<<endl;
	
	return 0;
}
