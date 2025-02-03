// Problem Link: https://codeforces.com/problemset/problem/1675/E
// Solution Link: https://www.youtube.com/watch?v=gGdA9yiRjWA

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;

        string s;
        cin>>s;

        int r = 0, l_ch, r_ch;
        for(int i=0;i<n;i++){
            int value = s[i]-'a';
            if(value <= r)    continue;

            int diff = value - r;
            if(diff > k){
                l_ch = value - k;
                r_ch = value;
                break;
            }
            r = value;
            k -= diff;
        }

        for(int i=0;i<n;i++){
            int value = s[i]-'a';
            if(value <= r )  s[i] = 'a';
            else if(value <= r_ch && value >= l_ch) s[i] = ('a' + l_ch);
            cout<<s[i];
        }
        cout<<endl;
    }

    return 0;
}
