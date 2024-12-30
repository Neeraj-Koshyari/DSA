// Problem Link: https://codeforces.com/problemset/problem/1873/F
// Solution Link: https://www.youtube.com/watch?v=oDFa5EkQjHo

// --------------------------- Binary serach solution from line 51 ------------------------------ \\

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
		int n,k;
		cin>>n>>k;

		vector<int> a(n), h(n);
		for(int i=0;i<n;i++)	cin>>a[i];
		for(int i=0;i<n;i++)	cin>>h[i];

		int l = 0, sum = a[0], ans = (a[0] <= k)? 1 : 0;
		for(int i=1; i<n; i++){
			if(h[i-1] % h[i] == 0)	sum += a[i];
			else{
				sum = a[i];
				l = i;
			}

			while(sum > k){
				sum -= a[l];
				l++;
			}

			ans = max(ans, i-l+1);
		}
		cout<<ans<<endl;	
	}

	return 0;
}


// -------------------------- Binary Search Solution ----------------------------------- \\
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool ok(int len, vector<int>& a, vector<int>& h, int k){
	int l = 0, sum = a[0], ans = 1e9+1, n = a.size();
	for(int i=1; i<n; i++){
		if(h[i-1] % h[i] == 0)	sum += a[i];
		else{
			sum = a[i];
			l = i;
		}

		while(i-l+1 > len){
			sum -= a[l];
			l++;
		}

		if(i-l+1 == len)	ans = min(ans,sum);
	}

	return ans <= k;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;

	while(t--){
		int n,k,mn=1e9;
		cin>>n>>k;

		vector<int> a(n), h(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
			mn = min(mn,a[i]);
		}
		for(int i=0;i<n;i++)	cin>>h[i];

		if(mn > k){
			cout<<0<<endl;
			continue;
		}

		int l = 1, r = n+1;
		while(l+1 < r){
			int mid = (l+r)/2;
			if(ok(mid,a,h,k))	l = mid;
			else r = mid;
		}

		cout<<l<<endl;
	}

	return 0;
}
