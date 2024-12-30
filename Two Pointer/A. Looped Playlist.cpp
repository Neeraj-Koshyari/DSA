// Problem Link: https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/A
// Solution Link: https://www.youtube.com/watch?v=dtGXCnfHz7M

/* 
  Observation:
    Problem Says we can listen the song multiple time. But the catch is after listning to i'th song we have to move forward.
    we can listen the current song after looping.
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n,k,total = 0;
	cin>>n>>k;

	vector<ll> v(n);
	for(int i=0;i<n;i++){	
		cin>>v[i];
		total += v[i];
	}

	ll temp_k = k%total;

	ll l = 0, idx = 0, sum = 0, len = n;
	for(int i=0;i<2*n;i++){
		sum += v[i%n];

		while(sum >= temp_k){
			if(i-l+1 < len){
				len = i-l+1;
				idx = l%n;
			}
			sum -= v[l%n];
			l++;
		}
	}

	cout<<idx+1<<" "<<k/total*n + len<<endl;

	return 0;
}
