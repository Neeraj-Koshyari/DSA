// Problem Link: https://codeforces.com/problemset/problem/930/B

/*
  Hint:
    How many time we can uniquely identify all occurance of a character with same length
    example: 
        "abcab"

      occurancences 
        a - > 0, 3 (index)
        b - > 1, 4
        c - > 2

      for all 'a' determining all pairs of same length:
        length 1 -> ab, ab    unique pairs = 0
        length 2 -> ac, aa    unique pairs = 2
        length 3 -> aa, ab    unique pairs = 2
        ...
        so for charater 'a' we can achinve maximum unique less of 2 with length 2,3..
        for b = 2
        for c = 1
        add all these uniqueness and divide it by n we will be maximum probapility of winning.
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

    string s;
    cin>>s;

    int n = s.length();
    double ans = 0;

    vector<vector<int>> v(26);
    for(int i=0;i<n;i++)    v[s[i]-'a'].push_back(i);

    cout<<fixed<<setprecision(8);

    for(int i=0;i<26;i++){
        if(v[i].size() == 0)  continue;

        int c = 0;
        for(int len=0; len<n; len++){
            int count = 0;
            vector<int> temp(26);
            for(auto& x:v[i])   temp[s[(x+len)%n] - 'a']++;

            for(auto& x:temp){
                if(x == 1)  count++;
            }
            c = max(c,count);
        }
        ans += c;
    }
    ans = ans/(double)n;
    cout<<ans<<endl;

    return 0;
}
