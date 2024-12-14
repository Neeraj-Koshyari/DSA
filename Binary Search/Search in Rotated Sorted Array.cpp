//Problem Link: https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int l = 0, r = arr.size()-1;
        
        while(l <= r){
            int mid = (l+r)/2;
            
            if(arr[mid] == key) return mid;
            
            if(arr[mid] >= arr[l]){
                if(key >= arr[l] && key <= arr[mid])   r = mid-1;
                else l = mid+1;
            }
            else{
                if(key <= arr[r] && key >= arr[mid])   l = mid+1;
                else r = mid-1;
            }
        }
        return -1;
    }
};
