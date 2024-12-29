// Problem Link: https://codeforces.com/contest/701/problem/C
// Solution Link: https://www.youtube.com/watch?v=G4nRKSg-DU8


// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;

	string s;
	cin>>s;

	map<char,int> mp;
	for(int i=0;i<n;i++)	mp[s[i]] = 1;
	
	int count = mp.size(), l = 0, ans = 1e9;

	for(int i=0;i<n;i++){
		if(mp[s[i]] > 0)	count--;
		mp[s[i]]--;

		while(count == 0){
			mp[s[l]]++;

			if(mp[s[l]] > 0)	count++;
			ans = min(ans, i-l+1);
			l++;
		}
	}

	cout<<ans<<endl;

	return 0;
}
