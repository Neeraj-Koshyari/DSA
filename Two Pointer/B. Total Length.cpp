// Problem Link: https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/B
// Solution Link: https://www.youtube.com/watch?v=zGNYIljFR5A

// Read the statement for why at line 34 we added sum of all length in segment again
// Because according to the question add the length of all element which is in the segment so, let [1,1] is a good segment and 
// [1,2] is also good segment then all length in [1,1] is {1} and in [1,2] is {1,2} so we have to add 1 again for another segement

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n,s;
	cin>>n>>s;

	vector<ll> v(n);
	for(int i=0;i<n;i++)	cin>>v[i];

	ll sum = 0, l = 0, ans = 0;

	for(int i=0; i<n; i++){
		sum += v[i];

		while(sum > s){
			sum -= v[l];
			l++;
		}
		ll len = i-l+1;
		ans += (len * (len+1))/2;
	}

	cout<<ans<<endl;
	return 0;
}
