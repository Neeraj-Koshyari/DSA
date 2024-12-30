// Problem Link: https://codeforces.com/problemset/problem/1225/B2
// Solution Link: https://www.youtube.com/watch?v=jN1oyVBZtuk


// ------------------------ another approch using hash table(at line 46) but got TLE -------------------------- \\

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	
	while(t--){
		int n,k,d;
		cin>>n>>k>>d;

		vector<int> v(n);
		for(int i=0;i<n;i++)	cin>>v[i];

		map<int,int> mp;
		for(int i=0;i<d;i++)	mp[v[i]]++;

		int ans = mp.size();
		for(int i = d; i<n; i++){
			mp[v[i-d]]--;
			if(mp[v[i-d]] == 0)	mp.erase(v[i-d]);

			mp[v[i]]++;
			ans = min(ans,(int)mp.size());
		}
		cout<<ans<<endl;
	}

	return 0;
}


// The Below solution got TLE in test case
// 10000
// 1 1000000 1
// 1
// 10000
// 1 1000000 1
// 1
// 10000
// 1 1000000 1
// 1
// ......... 10000 times

// The main cause for TLE is creating array of size k which take k time for all t test cases so time complexity is t*k (1e4 * 1e6 = 1e10)
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	
	while(t--){
		int n,k,d;
		cin>>n>>k>>d;

		vector<int> v(n);
		for(int i=0;i<n;i++)	cin>>v[i];

		int count = 0;
		vector<int> freq(k+1);
		for(int i=0;i<d;i++){
			freq[v[i]]++;
			if(freq[v[i]] == 1)	count++;
		}

		int ans = mp.size();
		for(int i = d; i<n; i++){
			freq[v[i-d]]--;
			if(freq[v[i-d]] == 0)	count--;

			freq[v[i]]++;
			if(freq[v[i]] == 1)	count++;
			
			ans = min(ans,count);
		}

		cout<<ans<<endl;
	}

	return 0;
}
