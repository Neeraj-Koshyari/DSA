// Problem Link: https://codeforces.com/problemset/problem/679/A

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void find(){
	vector<int> prime = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

	int flag = -1;
	for(int i=0;i<4;i++){
		string s;
		cout<<prime[i]<<endl;
		cin>>s;
		if(s == "yes"){
			flag = i;
			break;
		}
	}

	if(flag == -1){
		cout<<"prime"<<endl;
		return;
	}

	int val = prime[flag];
	val *= val;
	string s;

	cout<<val<<endl;
	cin>>s;

	if(s == "yes"){
		cout<<"composite"<<endl;
		return;
	}

	for(int i = flag+1; i<15;i++){
		cout<<prime[i]<<endl;
		cin>>s;

		if(s == "yes"){
			cout<<"composite"<<endl;
			return;
		}
	}
	cout<<"prime"<<endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	find();

    return 0;
}
