// Problem Link: https://cses.fi/problemset/task/1077

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

	vector<ll> v(n),ans;
	for(int i=0;i<n;i++)	cin>>v[i];

	multiset<ll> left, right;
	ll sum_left = 0, sum_right =  0;

	auto balance = [&](){
		if(right.size() > left.size()){
			ll x = *right.begin();
			left.insert(x);
			
			sum_left += x;
			sum_right -= x;

			right.erase(right.begin());
		}

		if(left.size() - 1 > right.size()){
			ll x = *left.rbegin();
			left.erase(prev(left.end()));

			sum_left -= x;
			sum_right += x;

			right.insert(x);
		}
	};

	for(int i=0; i<n; i++){
		if(left.size() == 0 || v[i] <= *left.rbegin()){
			left.insert(v[i]);
			sum_left += v[i];
		}
		else{ 
			right.insert(v[i]);
			sum_right += v[i];
		}
		balance();

		if(i >= k){
			if(v[i-k] <= *left.rbegin()){
				left.erase(left.find(v[i-k]));
				sum_left -= v[i-k];
			}
			else{
				right.erase(right.find(v[i-k]));
				sum_right -= v[i-k];
			}

			balance();
		}

		if(i >= k-1){
			ll x = sum_right - sum_left;
			if(k&1)	x += *left.rbegin();
			cout<<x<<" ";
		}
	}

	return 0;
}
