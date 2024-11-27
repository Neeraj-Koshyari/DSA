// Problem Link: https://codeforces.com/problemset/problem/1167/B

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int Ask(int l, int r){
	cout<<"? "<<l<<" "<<r<<endl;

	int x;
	cin>>x;

	return x;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	map<int,pair<int,int>> mp = {{32,{4,8}}, {60,{4,15}}, {64,{4,16}}, {92,{4,23}}, {168,{4,42}},
								{120,{8,15}}, {128,{8,16}}, {184,{8,23}}, {336,{8,42}},
								{240,{15,16}}, {345,{15,23}}, {630,{15,42}},
								{368,{16,23}}, {672,{16,42}},
								{966,{23,42}}};
	vector<int> v(6);
	pair<int,int> a = mp[Ask(1,2)];
	pair<int,int> b = mp[Ask(2,3)];

	if(a.first == b.first || a.first == b.second){
		v[0] = a.second;
		v[1] = a.first;

		if(a.first == b.first)	v[2] = b.second;
		else v[2] = b.first;
	}
	else{
		v[0] = a.first;
		v[1] = a.second;

		if(a.second == b.first)	v[2] = b.second;
		else v[2] = b.first;
	}

	a = mp[Ask(4,5)];
	b = mp[Ask(5,6)];
	if(a.first == b.first || a.first == b.second){
		v[3] = a.second;
		v[4] = a.first;

		if(a.first == b.first)	v[5] = b.second;
		else v[5] = b.first;
	}
	else{
		v[3] = a.first;
		v[4] = a.second;

		if(a.second == b.first)	v[5] = b.second;
		else v[5] = b.first;
	}

	cout<<"! ";
	for(int i=0;i<6;i++)	cout<<v[i]<<" ";
	cout<<endl;
    return 0;
}
