// Problem Link: https://www.geeksforgeeks.org/problems/search-pattern0205/1


// Using z function
class Solution {
  public:
    vector<int> z_fun(string& s){
        int l = 0, r = 0, n = s.length();
        vector<int> z(n);
        
        for(int i=1; i<n; i++){
            if(r > i){
                z[i] = min(r-i,z[i-l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]])   z[i]++;
            
            if(i + z[i] > r){
                r = i + z[i];
                l = i;
            }
        }
        return z;
    }
  
    vector<int> search(string& pat, string& txt) {
        // code here
        string s = pat + '$' + txt;
        
        vector<int> z = z_fun(s), ans;
        
        int m = pat.size(), n = z.size();
        for(int i=m; i<n; i++){
            if(z[i] == m)   ans.push_back(i-m-1);
        }
        return ans;
    }
};
