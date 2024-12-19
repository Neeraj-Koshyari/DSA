// Problem Link: https://www.geeksforgeeks.org/problems/kth-missing-positive-number-in-a-sorted-array/1

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int l = -1, r = arr.size();
        
        while(l+1 < r){
            int mid = (l+r)/2;
            
            if(arr[mid] - (mid+1) < k) l = mid;
            else r = mid;
        }
        return k + l + 1;
    }
};
