// Problem Link: https://codeforces.com/problemset/problem/1084/C
// Solution Link: https://www.youtube.com/watch?v=Ct5jl1SytiQ

/*
  Hint: 
    let say our string compress down to "aa...bb....aa...bb...aa..."
    so, to choosing 1st segment and 3rd segment give us answer by length of seg 1 and len of seg 3
    and we can also choose from seg 1 and seg 5 and so on.

Hint 1: Imagin we have an empty charater in each segment of 'a'.
    
    So, to calculate this what we can do is add an emptry character in each segment.
    So, when we will multiply seg1 * seg3 * seg5 * ....  then an empty character will also be multiplied which will give as
    seg1 * seg 5 as in seg 3 we will choose empty character. similarly, seg1 * seg3 and seg3 * seg5 will be calculated just by multipling each segment
    at the end there will be a case where we have choosen all empty character from each segment.
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

    ll ans = 1, count = 0, mod = 1e9+7;
    for(auto& ch:s){
        if(ch == 'a') count++;
        else if(ch == 'b'){
            ans = (ans * (count+1))%mod;
            count = 0;
        }
    }
    ans = (ans * (count+1))%mod;
    cout<<ans-1<<endl;

    return 0;
}
