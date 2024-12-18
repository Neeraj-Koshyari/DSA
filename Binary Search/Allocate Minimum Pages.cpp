// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

class Solution {
  public:
    bool ok(vector<int>& arr, int mx, int k){
        int count = 1, sum = 0;
        
        for(auto& x:arr){
            if(sum + x > mx){
                count++;
                sum = x;
            }
            else sum += x;
        }
        
        return count <= k;
    }
  
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n < k)   return -1;
        
        int l = *max_element(arr.begin(),arr.end())-1, r = 1e9;
        
        while(l+1<r){
            int mid = (l+r)/2;
            
            if(ok(arr,mid, k)) r = mid;
            else l = mid;
        }
        
        return r;
    }
};
