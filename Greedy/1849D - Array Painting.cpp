// Problem Link: https://codeforces.com/problemset/problem/1849/D

// Solution copied

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, coin = 0, l = 0;
    cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++)  cin>>v[i];

    while(l<n){
        int r = l+1;
        bool hasTwo = (v[l] == 2), midZero = false;

        while(r < n){
            if(r-1 > l && v[r-1] == 0)  midZero = true;
            if(v[r] == 2)   hasTwo = true;
            if(!(!midZero && (hasTwo || v[l] != 0 || v[r] != 0)))  break;

            r++;
        }
        l=r;
        coin++;
    }

    cout<<coin<<endl;

    return 0;
}
