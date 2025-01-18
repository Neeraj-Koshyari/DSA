// Problem Link: https://cses.fi/problemset/task/1713


/*
  20  -> 2^2  *  5^1
  ans -> (2 + 1)  *  (1 + 1)  -> 6    ( 1, 2, 4, 5, 10, 20 )
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

    int N = 1e6+1;
    vector<int> spf(N,1e9);
    for(int i = 2; i<N; i++){
        if(spf[i] != (int)1e9)  continue;

        for(int j = i; j<N; j+=i)   spf[j] = min(spf[j], i);
    }

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        ll ans = 1, temp = n;
        while(n != 1){
            int fact = spf[n], count = 0;

            while(n%fact == 0){
                n /= fact;
                count++;
            }

            ans *= (count+1);
        }
        cout<<ans<<endl;
    }


    return 0;
}
