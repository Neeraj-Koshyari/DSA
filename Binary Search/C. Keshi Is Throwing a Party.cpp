// Problem Link: https://codeforces.com/problemset/problem/1610/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool ok(int x, vector<int>& a, vector<int>& b){
	int n = a.size(), rich_count = 0;
	for(int i = n-1; i >= 0; i--){
		if(a[i] >= rich_count && b[i] >= x-rich_count)	rich_count++;
	}

	return rich_count > x;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<int> a(n),b(n);
		for(int i=0;i<n;i++)	cin>>a[i]>>b[i];

		int l = -1, r = n;
		while(l+1 < r){
			int mid = (l+r)/2;

			if(ok(mid,a,b))	l = mid;
			else r = mid;
		}
		cout<<l+1<<endl;
	}
	return 0;
}
