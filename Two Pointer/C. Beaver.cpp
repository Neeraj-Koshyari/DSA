// Problem Link: https://codeforces.com/contest/79/problem/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool check(int l, int r, vector<string>& v, string& s){
	for(auto& x:v){
		int n = x.length()-1, idx = r;
		while(n >= 0 && idx >= l && s[idx] == x[n]){
			idx--;
			n--;
		}
		if(n == -1)	return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin>>s;

	int n = s.length(),t;
	cin>>t;

	vector<string> v(t);
	for(int i=0;i<t;i++)	cin>>v[i];

	int l = 0, ans = 0, start_idx = 0;
	for(int i=0; i<n; i++){
		while(check(l, i, v, s))	l++;

		if(i-l+1 > ans){
			ans = i-l+1;
			start_idx = l;
		}
	}
	cout<<ans<<" "<<start_idx<<endl;
	return 0;
}
