// Problem Link : https://www.geeksforgeeks.org/problems/minimum-sum4058/1

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        string x, y;
        for(int i=0;i<n;i+=2){
            if(x.length() == 0){
                if(arr[i] != 0) x += char(arr[i] + '0');
            }
            else x += char(arr[i] + '0');
            
            if(i+1 < n){
                if(y.length() == 0){
                    if(arr[i+1] != 0) y += char(arr[i+1] + '0');
                }
                else y += char(arr[i+1] + '0');
            }
        }
        
        // cout<<x<<" "<<y<<endl;
        
        n = x.length();
        int m = y.length(), carry = 0;
        
        if(m > n){
            swap(x,y);
            swap(n,m);
        }
        
        for(int i = 0; i<m; i++){
            int val = (x[n-1-i]-'0') + (y[m-1-i]-'0') + carry;
            x[n-1-i] = char(val%10 + '0');
            carry = val/10;
        }
        
        for(int i = m; i<n; i++){
            if(carry == 0)  break;
            
            int val = (x[n-1-i]-'0') + carry;
            x[n-1-i] = char(val%10 + '0');
            carry = val/10;
        }
        
        if(carry)   x = '1'+x;
        
        return x;
    }
};
