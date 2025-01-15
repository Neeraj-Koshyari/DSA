// Problem Link: https://cses.fi/problemset/task/1081
// Solution Link: https://www.youtube.com/watch?v=h1nOsinSTBg

// Hint: Sieve ( N/1 + N/2 + N/3 + ........... + N/N  = Nlog(N) )

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, N = 1e6+1;
    cin>>n;

    vector<int> v(N);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v[x]++;
    }

    for(int i=N-1;i>0;i--){
        int count = 0;
        for(int j=i;j<N;j+=i)   count += v[j];

        if(count > 1){   
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}
