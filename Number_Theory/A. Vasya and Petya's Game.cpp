// Problem Link: https://codeforces.com/problemset/problem/576/A
// Solution Link: https://www.youtube.com/watch?v=8stE0jz-Xp4

// Hint: try smallest prime factor's values

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 1e3+1;
    vector<int> spf(N,1e9);
    
    for(int i=2;i<N;i++){
        if(spf[i] != (int)1e9)  continue;

        for(int j = i; j<N; j += i) spf[j] = min(spf[j], i);
    }

    set<int> st;
    vector<int> ans;

    int n;
    cin>>n;

    for(int i=2; i<=n; i++){
        int x = i;
        while(x != 1){
            int fact = spf[x];
            int val = 1;
            while(x % fact == 0){
                val *= fact;
                x /= fact;
            }
            if(!st.count(val)){
                st.insert(val);
                ans.push_back(val);
            }
        }
    }

    cout<<(int)ans.size()<<endl;
    for(auto& x:ans)    cout<<x<<" ";

    return 0;
}
