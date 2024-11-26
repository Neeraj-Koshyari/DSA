//Problem Link: https://codeforces.com/problemset/problem/1425/F

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

	vector<int> v(n);

	int a,b;
	cout<<"? "<<1<<" "<<n<<endl;
	cin>>b;

	for(int i=1; i<n-1; i++){
		a = b;

		cout<<"? "<<i+1<<" "<<n<<endl;
		cin>>b;

		v[i-1] = a - b;
	}

	int c;
	cout<<"? "<<n-2<<" "<<n-1<<endl;
	cin>>c;

	v[n-2] = b + c - a;
	v[n-1] = a - c;

	cout<<"! ";
	for(int i=0;i<n;i++)	cout<<v[i]<<" ";
    return 0;
}
