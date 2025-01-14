// Problem Link: https://codeforces.com/contest/1826/problem/B
// Solution Link: https://www.youtube.com/watch?v=d4mAb6ZUBz0

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int find(){
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++)    cin>>v[i];

    int val = -1, i = 0, j = n-1;
    while(i<j){
        if(val == -1){
            if(v[i] != v[j])    val = abs(v[i]-v[j]);
        }
        else{
            if(v[i]%val != v[j]%val){
                int x = abs(v[i]-v[j]);
                val = gcd(val,x);
            }
        }
        i++;
        j--;
    }
    if(val == -1)   return 0;
    return val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	int t;
    cin>> t;

    while(t--){
        cout<<find()<<endl;
    }

    return 0;
}
