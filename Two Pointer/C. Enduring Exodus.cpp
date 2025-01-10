// https://codeforces.com/contest/645/problem/C

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin>>n>>k;
	k++;

	string s;
	cin>>s;

	vector<int> v;

	for(int i=0; i<n; i++){
		if(s[i] == '0')	v.push_back(i);
	}

	int m = v.size(), it = 0, ans = 1e9;
	for(int i=k; i<=m; i++){
		while(max(v[it+1] - v[i-k], v[i-1] - v[it+1]) < max(v[it] - v[i-k], v[i-1] - v[it])){
			it++;
		}
		ans = min(ans, max(v[it] - v[i-k], v[i-1] - v[it]));
	}
	cout<<ans<<endl;

	return 0;
}
