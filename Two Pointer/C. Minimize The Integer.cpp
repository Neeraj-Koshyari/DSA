// Problem Link: https://codeforces.com/problemset/problem/1251/C
// Solution Link: https://www.youtube.com/watch?v=HGEaSk_vBfI

/*
Observation:
  odd and even number are indenpendent of each other.
  It dosen't matter what is the poition of even number or odd number.
  only matter is the order of odd number or even number.

  ex: 012345678
  we can place all odd in one corner and all even in one corner ( 02468 1357 ) now we can use 2 pointers to place the min value first
  but notice that we can't change the order of the odd number or even number.
*/
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	
	while(t--){
		string s, ans;
		cin>>s;

		int i = 0, j = 0, n = s.length();
		while(i<n || j<n){
			while(i<n && (s[i]-'0')%2 != 0)	i++;
			while(j<n && (s[j]-'0')%2 == 0)	j++;

			if(i<n && j<n){
				if(s[i] < s[j]){
					ans += s[i];
					i++;
				}
				else{
					ans += s[j];
					j++;
				}
			}
			else if(i<n){
				ans += s[i];
				i++;
			}
			else if(j<n){
				ans += s[j];
				j++;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
