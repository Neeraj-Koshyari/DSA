// Problem Link: https://codeforces.com/problemset/problem/1799/C
// Solution Link: https://www.youtube.com/watch?v=pWwKg2Y9jTg

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
        string s;
        cin>>s;

        int n = s.length();
        sort(s.begin(),s.end());

        string temp = s;
        int l = 0, r = n-1,i=0;

        for(i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                temp[l] = temp[r] = s[i];
                l++;
                r--;
                i++;
            }
            else if(s[i+1] == s[n-1]){
                int len = (n-i-1);
                int left = (len+1)/2, right = (len/2);
                while(right--){
                    temp[l] = temp[r] = s[n-1];
                    l++;
                    r--;
                    left--;
                }
                if(left){
                    temp[l] = s[n-1];
                    l++;
                }
                temp[l] = s[i];
                i = n;
                break;
            }
            else{
                temp[r] = s[i];
                temp[l] = s[i+1];
                i+=2;
                l++;
                break;
            }
        }
        while(i<n){
            temp[l] = s[i];
            i++;
            l++;
        }
        cout<<temp<<endl;
    }

    return 0;
}
