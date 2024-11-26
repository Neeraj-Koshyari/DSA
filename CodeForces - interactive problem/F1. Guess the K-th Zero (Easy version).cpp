// Problem Link: https://codeforces.com/problemset/problem/1520/F1

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int Ask(int l, int r){
	int x;
	cout<<"? "<<l<<" "<<r<<endl;
	cin>>x;

	return r-l+1 - x;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,t;
	cin>>n>>t;

	while(t--){
		int k;
		cin>>k;

		int l=1, r=n;
		while(l<=r){
			int mid = (l+r)/2;
			int zeros = Ask(l,mid);
			if(zeros < k){
				k -= zeros;
				l = mid+1;
			}
			else r = mid-1;
		}
		cout<<"! "<<l<<endl;
	}
    return 0;
}
