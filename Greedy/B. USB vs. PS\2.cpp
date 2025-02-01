// Problem Link: https://codeforces.com/contest/762/problem/B
// Solution Link: https://www.youtube.com/watch?v=GMCMpDpkeIY

// #include<fstream>
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c,m;
    cin>>a>>b>>c>>m;

    vector<int> usb, ps2;
    for(int i=0;i<m;i++){
        int x;
        string s;
        cin>>x>>s;
        if(s[0] == 'U') usb.push_back(x);
        else ps2.push_back(x);
    }

    sort(usb.begin(),usb.end());
    sort(ps2.begin(),ps2.end());

    ll usb_size = usb.size(), ps2_size = ps2.size(), i=0, j=0, items = 0, amount = 0;
    while(i < usb_size && a > 0){
        items++;
        amount += usb[i];
        i++;
        a--;
    }

    while(j < ps2.size() && b > 0){
        items++;
        amount += ps2[j];
        j++;
        b--;
    }

    while(c--){
        if(i < usb_size && j < ps2_size){
            if(ps2[j] < usb[i]) amount += ps2[j++];
            else amount += usb[i++];
        }
        else if(i < usb_size)   amount += usb[i++];
        else if(j < ps2_size)   amount += ps2[j++];
        else break;

        items++;
    }

    cout<<items<<" "<<amount<<endl;

    return 0;
}
