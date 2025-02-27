// Problem Link: https://www.spoj.com/problems/DEFKIN/
// Solution Link: https://www.youtube.com/watch?v=-FhXYFO3yBE

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

    while (t--){
        int weight,height,n;
        cin>>weight>>height>>n;

        vector<int> w(n), h(n);
        for(int i=0;i<n;i++)    cin>>w[i]>>h[i];

        w.push_back(0);
        w.push_back(weight+1);

        h.push_back(0);
        h.push_back(height+1);

        n += 2;

        sort(w.begin(), w.end());
        sort(h.begin(), h.end());

        int l = 0, r = 0;
        for(int i=1; i<n; i++){
            l = max(l, w[i] - w[i-1]);
            r = max(r, h[i] - h[i-1]);
        }

        cout<<(l-1) * (r-1)<<endl;
    }
    return 0;
}
