// Problem Link: https://www.naukri.com/code360/problems/n-queens_759332?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
 
vector<int> arr(11);

void display(int n, vector<vector<int>>& ans){
    vector<int> v;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (arr[i] != j)    v.push_back(0);
            else    v.push_back(1);
        }
    }
    ans.push_back(v);
}

bool canPlace(int k, int i){
    for (int j = 1;j <= k - 1;j++){
        if (arr[j] == i || (abs(arr[j] - i) == abs(j - k)))
           return false;
    }
    return true;
}

void place_Queens(int k, int n,vector<vector<int>>& ans){
 
    for (int i = 1;i <= n;i++){
        if (canPlace(k, i)){
            arr[k] = i;
            if (k == n){
                display(n,ans);
            }
            else    place_Queens(k + 1, n, ans);
        }
    }
}
 

vector<vector<int>> solveNQueens(int n)
{
	// Write your code here
	vector<vector<int>> ans;
	place_Queens(1,n,ans);
	return ans;
}
