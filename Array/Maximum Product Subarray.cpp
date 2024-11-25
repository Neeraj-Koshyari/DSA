// Problem Link: https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1

class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int left = 1, right = 1, ans = -1e9, n = arr.size();
        for(int i=0;i<n;i++){
            left *= arr[i];
            right *= arr[n-1-i];
            
            ans = max({ans,left,right});
            
            if(left == 0)   left = 1;
            if(right == 0)  right = 1;
        }
        return ans;
    }
};
