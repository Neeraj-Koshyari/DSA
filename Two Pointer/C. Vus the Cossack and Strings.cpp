// Problem Link: https://codeforces.com/contest/1186/problem/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s,t;
	cin>>s>>t;

	int c1 = 0, c2 = 0, n = s.length(), m = t.length(), ans = 0;
	for(int i=0; i<m; i++){
		if(s[i] == '1')	c1++;
		if(t[i] == '1') c2++;
	}

	if(c1%2 == c2%2)	ans++;

	for(int i=m; i<n; i++){
		if(s[i-m] == '1')	c1--;
		if(s[i] == '1')	c1++;

		if(c1%2 == c2%2)	ans++;
	}
	cout<<ans<<endl;
	return 0;
}
