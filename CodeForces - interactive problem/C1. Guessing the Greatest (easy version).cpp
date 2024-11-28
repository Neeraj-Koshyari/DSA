// Problem Link: https://codeforces.com/problemset/problem/1486/C1

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int Ask(int l, int r){
	cout<<"? "<<l<<" "<<r<<endl;
	int x;
	cin>>x;

	return x;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin>>N;

	int second_mx = Ask(1,N), idx;
	
	if(second_mx == 1 || second_mx == N)	idx = N;
	else idx = Ask(1,second_mx);

	if(idx == second_mx){	
		int l = 1, r = second_mx;

		while(l+1 < r){
			int mid = (l+r)/2;

			if(Ask(mid,second_mx) == second_mx)	l = mid;
			else r = mid;
		}
		cout<<"! "<<l<<endl;
	}
	else{
		int l = second_mx, r = N;

		while(l+1 < r){
			int mid = (l+r)/2;

			if(Ask(second_mx, mid) == second_mx)	r = mid;
			else l = mid;
		}
		cout<<"! "<<r<<endl;
	}
	return 0;
}
