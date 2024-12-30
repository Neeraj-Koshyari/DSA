// Problem Link: https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/F
// Solution Link: https://www.youtube.com/watch?v=KYfduQMoarQ

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n,k;
	cin>>n>>k;

	vector<ll> v(n);
	for(int i=0;i<n;i++)	cin>>v[i];

	set<pair<ll,ll>> st;
	ll l = 0, ans = 0;

	for(int i=0;i<n;i++){
		st.insert({v[i],i});

		ll diff = (*st.rbegin()).first - (*st.begin()).first;
		while(diff > k){
			st.erase({v[l],l});
			diff = (*st.rbegin()).first - (*st.begin()).first;
			l++;
		}

		ans += (i-l+1);
	}

	cout<<ans<<endl;

	return 0;
}
