// Problem Link: https://codeforces.com/problemset/problem/1698/D

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool Ask(int l, int r){
	cout<<"? "<<l<<" "<<r<<endl;
	int count = 0;

	for(int i=l;i<=r;i++){
		int x;
		cin>>x;

		if(x>=l && x<=r)	count++;
	}

	return count&1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		int l = 1, r = n;
		while(l < r){
			int mid = (l+r)/2;

			if(Ask(l, mid))	r = mid;
			else l = mid+1;
		}		
		cout<<"! "<<r<<endl;
	}
	return 0;
}
