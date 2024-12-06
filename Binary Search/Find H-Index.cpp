// Problem Link: https://www.geeksforgeeks.org/problems/find-h-index--165609/1

class Solution {
  public:
    // Function to find hIndex
    bool ok(int val, vector<int>& v){
        int count = 0;
        for(auto& x:v){
            if(x >= val)    count++;
        }
        return count >= val;
    }
    
    int hIndex(vector<int>& citations) {
        // code here
        
        int l = 0, r = 1e6+1;
        while(l+1 < r){
            int mid = (l+r)/2;
            
            if(ok(mid,citations))   l = mid;
            else r = mid;
        }
        return l;
    }
};
