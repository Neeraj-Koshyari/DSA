// Problem Link: https://codeforces.com/problemset/problem/898/D
// Solution Link: https://www.youtube.com/watch?v=fkLKHz6S0_A

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k, count = 0;
    cin>>n>>m>>k;

    vector<int> v(n);
    deque<int> qu;
    for(int i=0;i<n;i++)    cin>>v[i];

    sort(v.begin(),v.end());

    for(int i=0;i<n;i++){
        qu.push_back(v[i]);

        if(qu.size() == k){
            int x = qu.front();
            int y = qu.back();

            if((y-x) < m){
                count++;
                qu.pop_back();
            }
            else qu.pop_front();
        }
    }

    cout<<count<<endl;
    return 0;
}
