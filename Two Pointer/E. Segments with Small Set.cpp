// Problem Link: https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/E
// Solution Link: https://www.youtube.com/watch?v=D1uXjKwxwms

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	cin>>n>>k;

	vector<int> v(n);
	for(int i=0; i<n; i++)	cin>>v[i];

	map<int,int> mp;
	ll ans = 0, count = 1, l = 0;

	for(int i=0; i<n; i++){
		mp[v[i]]++;

		while(mp.size() > k){
			mp[v[l]]--;
			if(mp[v[l]] == 0)	mp.erase(v[l]);
			l++;
			count--;
		}
		
		ans += count;
		count++;
	}

	cout<<ans<<endl;

	return 0;
}
