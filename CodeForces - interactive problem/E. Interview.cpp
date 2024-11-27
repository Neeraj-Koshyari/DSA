// Problem Link: https://codeforces.com/contest/1807/problem/E

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool Ask(int n, vector<int>& v){
	int x, sum = 0;;
	cout<<"? "<<n<<" ";
	for(int i=0;i<n;i++){	
		cout<<i+1<<" ";
		sum += v[i];
	}
	cout<<endl;
	cin>>x;

	return sum == x;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		vector<int> v(n);
		for(int i=0;i<n;i++)	cin>>v[i];

		int l = -1, r = n-1;
		while(l+1 < r){
			int mid = (l+r)/2;

			if(Ask(mid+1,v))	l = mid;
			else r = mid;
		}
		cout<<"! "<<r+1<<endl;
	}
    return 0;
}
