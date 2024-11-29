// Problem Link: https://www.geeksforgeeks.org/problems/add-binary-strings3805/1

class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        
        int n = s1.size(), m = s2.size(), carry = 0;
        
        while(s1[n-1] == '0'){   
            s1.pop_back();
            n--;
        }
        while(s2[m-1] == '0'){
            s2.pop_back();
            m--;
        }
        
        if(n < m){
            swap(n,m);
            swap(s1,s2);
        }
        
        for(int i=0; i<n; i++){
            if(i < m)   carry += (s2[i] - '0');
            carry += (s1[i] - '0');
            
            if(carry == 0){    
                s1[i] = '0';
                carry = 0;
            }
            else if(carry == 1){    
                s1[i] = '1';
                carry = 0;
            }
            else if(carry == 2){
                s1[i] = '0';
                carry = 1;
            }
            else{
                s1[i] = '1';
                carry = 1;
            }
        }
        
        if(carry)   s1 += '1';
        reverse(s1.begin(),s1.end());
        
        return s1;
    }
};
