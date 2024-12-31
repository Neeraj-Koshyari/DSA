// Problem Link: https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/C
// Solution Link: https://www.youtube.com/watch?v=nVj7lAxS6Z0

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r;
	cin>>n>>r;

	vector<int> v(n);
	for(int i=0;i<n;i++)	cin>>v[i];

	ll ans = 0, l = 0;
	for(int i=1;i<n;i++){
		while(v[i] - v[l] > r){
			ans += n-i;
			l++;
		}
	}

	cout<<ans<<endl;

	return 0;
}
