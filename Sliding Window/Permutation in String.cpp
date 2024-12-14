//Problem Link: https://leetcode.com/problems/permutation-in-string/description/
// Youtuble: https://www.youtube.com/watch?v=tDJBNYZSTHs

class Solution {
public:
    bool check(vector<int>& v){
        for(auto& x:v){
            if(x != 0)  return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        if(n > m)   return false;

        vector<int> v(26);

        for(int i=0;i<n;i++){    
            v[s1[i] - 'a']++;
            v[s2[i] - 'a']--;
        }

        for(int i=n;i<m;i++){
            if(check(v)) return true;

            v[s2[i-n] - 'a']++;
            v[s2[i] - 'a']--;
        }
        if(check(v))    return true;
        return false;
    }
};
