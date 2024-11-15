// Problem Link : https://www.naukri.com/code360/problems/sort-an-array-according-to-the-count-of-set-bits_873142

#include <bits/stdc++.h> 

void sortSetBitsCount(vector<int>& arr, int n)
{
	// Write your code here
	map<int,vector<int>> mp;
	for(int i=0;i<n;i++){
		mp[__builtin_popcount(arr[i])].push_back(arr[i]);
	}

	int idx = 0;
	for(auto& x:mp){
		reverse(x.second.begin(),x.second.end());
		for(auto& y : x.second)	arr[idx++] = y;
	}
	reverse(arr.begin(),arr.end());
}
