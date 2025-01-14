// Problem Link: https://codeforces.com/problemset/problem/495/B
// Solution Link: https://www.youtube.com/watch?v=SWbda8QdUUc

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a,b;
    cin>>a>>b;

    if(a<b) cout<<0<<endl;
    else if(a==b)   cout<<"infinity"<<endl;
    else{
        ll val = a-b, count = 0;
        for(int i=1; i*i <= val; i++){
            if(val%i != 0)  continue;

            if(i > b)   count++;
            if(val/i != i && val/i > b) count++;
        }
        cout<<count<<endl;
    }

    return 0;
}
