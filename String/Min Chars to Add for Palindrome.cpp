// Problem Link: https://www.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1

//This z-function solution gives TLE in last testcases insted use KMP (solution given below)
class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
        int n = s.length();
        
        string ptn = s;
        reverse(s.begin(),s.end());
        
        int l = 0, r = 0, ans = n-1;
        
        vector<int> z(n);
        for(int i = 0; i < n; i++) {
            if(i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while(i + z[i] < n && ptn[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        
        for(int i=0;i<n;i++){
            if(z[i] == n-i)    ans = min(ans, n-z[i]);
        }
        return ans;
    }
};


// KMP
class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
        int n = s.length();
        
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string combined = s + "#" + rev_s;
        
        vector<int> pi(combined.length(), 0);
        for (int i = 1; i < combined.length(); i++) {
            int j = pi[i - 1];
            while (j > 0 && combined[i] != combined[j]) {
                j = pi[j - 1];
            }
            if (combined[i] == combined[j]) {
                j++;
            }
            pi[i] = j;
        }
        
        return n - pi.back();
    }
};
