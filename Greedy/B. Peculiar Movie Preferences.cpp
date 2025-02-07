// Problem Link: https://codeforces.com/problemset/problem/1628/B

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool pallin(string& s){
    int i=0,  j = s.length()-1;
    while(i<j){
        if(s[i] != s[j])    return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n; 
        cin>>n;

        vector<string> v(n);
        set<string> st2, st3;
        for(int i=0;i<n;i++)    cin>>v[i];

        int flag = 0;
        for(int i=0;i<n;i++){
            if(pallin(v[i])){
                flag = 1;
                break;
            }
            int m = v[i].length();
            string s;

            if(m == 3){
                s += v[i][2];
                s += v[i][1];

                if(st2.find(s) != st2.end())    flag = 1;

                s += v[i][0];
                if(st3.find(s) != st3.end())    flag = 1;

                st3.insert(v[i].substr(0,2));
                st3.insert(v[i]);
            }
            else{
                s += v[i][1];
                s += v[i][0];

                if(st2.find(s) != st2.end()) flag = 1;
                if(st3.find(s) != st3.end()) flag = 1;

                st2.insert(v[i]);
            }

            if(flag)    break;
        }
        if(flag)    cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    return 0;
}
