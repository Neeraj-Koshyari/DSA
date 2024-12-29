// Problem Link: https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C
// Solution Link: https://www.youtube.com/watch?v=OYqLM0y7__s

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin>>n>>m;

	vector<ll> a(n),b(m);
	for(int i=0;i<n;i++)	cin>>a[i];
	for(int i=0;i<m;i++)	cin>>b[i];

	a.push_back(1e9+1);
	b.push_back(1e9+2);
	n++;
	m++;

	int i = 1, j = 1;
	ll count_a = 1, count_b = 1, ans = 0;
	while(i<n && j<m){
		while(i<n && a[i] == a[i-1]){
			i++;
			count_a++;
		}

		while(j<m && b[j] == b[j-1]){
			j++;
			count_b++;
		}

		if(a[i-1] == b[j-1]){
			ans += (count_a * count_b);
			count_a = count_b = 1;
			i++;
			j++;
		}
		else if(a[i-1] > b[j-1]){
			count_b = 1;
			j++;
		}
		else{
			count_a = 1;
			i++;
		}
	}

	cout<<ans<<endl;

	return 0;
}
