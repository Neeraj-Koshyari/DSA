// Problem Link : https://www.geeksforgeeks.org/problems/minimum-times-a-has-to-be-repeated-such-that-b-is-a-substring-of-it--170645/1

class Solution {
  public:
    bool find(string& s, int m){
        int n = s.length(),l=0,r=0;
        vector<int> z(n);
        
        for(int i=1;i<n;i++){
            if(r > i)   z[i] = min(r-i, z[i-l]);
            
            while(i + z[i] < n && s[i + z[i]] == s[z[i]])   z[i]++;
            
            if(i + z[i] > r){
                r = i + z[i];
                l = i;
            }
        }
        
        for(int i = m; i<n; i++){
            if(z[i] == m)   return true;
        }
        return false;
    }
  
    int minRepeats(string& s1, string& s2) {
        // code here
        string temp = "";
        int n = s1.length(), m = s2.length(),count = 0;
        
        while(n*count < m){
            temp += s1;
            count++;
        }
        
        string temp2 = s2;
        temp2 += '$';
        temp2 += temp;
        
        if(find(temp2,m)) return count;
        
        temp2 += s1;
        count++;
        
        if(find(temp2,m)) return count;
        return -1;
    }
};
