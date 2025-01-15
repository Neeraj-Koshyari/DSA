// Problem Link: https://www.spoj.com/problems/HS08PAUL/
// Solution Link: https://www.youtube.com/watch?v=m94MmH1Q8xY

/*
  approch: precompute all the prime less then n ( as x^2 + y^4  gives time complexity less then 2e6 )
  hint : we can do 1e7 iteration
  */

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 1e7, n = 1e7;
    vector<int> prime(N,1), ans;
    prime[0] = prime[1] = 0;

    for(int i=2;i*i<N;i++){
        if(prime[i] == 0)   continue;

        for(int j = i*i; j<N; j += i)   prime[j] = 0;
    }

    for(int i=1;i<(int)1e4;i++){
        for(int j=1; i*i + j*j*j*j < n; j++){
            int val = i*i + j*j*j*j;
            if(prime[val]){
                ans.push_back(val);
                prime[val] = 0;
            }
        }
    }
    sort(ans.begin(), ans.end());

    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;

        cout<<upper_bound(ans.begin(), ans.end(), x) - ans.begin()<<endl;
    }

    return 0;
}
