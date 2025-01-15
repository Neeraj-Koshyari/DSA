// Problem Link: https://codeforces.com/problemset/problem/154/B
// Solutionhttps: www.youtube.com/watch?v=M54O-FKxYOY Link: 

// spf -> smallest prime factor

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int turnOff(int x, vector<int>& mp, vector<int>& spf){
    if(mp[x] != x)  return 0;
    
    mp[x] = 0;
    while(x != 1){
        int fact = spf[x];
        mp[fact] = 0;
        while(x % fact == 0) x /= fact;
    }
    return 1;
}

int turnOn(int x, vector<int>& mp, vector<int>& spf){
    if(mp[x] != 0)  return mp[x];

    int temp = x;
    while(temp != 1){
        int fact = spf[temp];
        if(mp[fact] != 0)   return mp[fact];

        while(temp % fact == 0) temp /= fact;
    }

    mp[x] = x;
    temp = x;
    while(temp != 1){
        int fact = spf[temp];
        mp[fact] = x;

        while(temp % fact == 0)    temp /= fact;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 1e5+1;
    vector<int> spf(N, 1e9);
    for(int i=2; i<N; i++){
        if(spf[i] != (int)1e9)   continue;
        for(int j=i; j<N; j += i) spf[j] = min(spf[j], i);
    }

    int n,m;
    cin>>n>>m;

    vector<int> mp(n+1);
    while(m--){
        char ch;
        int x;
        cin>>ch>>x;

        if(ch == '+'){
            int val = turnOn(x, mp, spf);
            if(val == 0)    cout<<"Success\n";
            else if(val == x)   cout<<"Already on\n";
            else cout<<"Conflict with "<<val<<endl;
        }else{
            if(turnOff(x, mp, spf))   cout<<"Success\n";
            else cout<<"Already off\n";
        }
    }

    return 0;
}
