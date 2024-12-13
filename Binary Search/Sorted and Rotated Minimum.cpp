//Problem Link: https://www.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1

class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int l = 0, r = arr.size()-1;
        
        while(l < r){
            if(arr[l] < arr[r]) break;
            
            int mid = (l+r)/2;
            
            if(arr[mid] > arr[r])   l = mid+1;
            else r = mid;
        }
        
        return arr[l];
    }
};
