// Problem Link: https://codeforces.com/problemset/problem/1742/F
// Solution Link: http://youtube.com/watch?v=gKFXIWb28_Y

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

char find(string& s, int n){
    char mx = 'a';
    for(int i=0;i<n;i++){
        mx = max(mx, s[i]);
    }

    return mx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        ll q, l1 = 1, l2 = 1;
        cin>>q;

        char mn1 = 'z', mx1 = 'a', mn2 = 'z', mx2 = 'a';
        while(q--){
            ll type, times, n;
            string s;
            cin>>type>>times>>s;

            n = s.length();
            char ch = find(s, n);
            if(type == 1){
                l1 += (times * 1ll * n);
                mx1 =  max(mx1, ch);
            }
            else{
                l2 += (times * 1ll * n);
                mx2 = max(mx2, ch);
            }

            if(mx2 > 'a')   cout<<"YES\n";
            else{
                if(mx1 > 'a' || l1 >= l2)    cout<<"NO\n";
                else cout<<"YES\n";
            }
        }
    }
       
    return 0;
}
