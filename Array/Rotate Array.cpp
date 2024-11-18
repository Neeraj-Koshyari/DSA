// Problem Link : https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1

class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void reverse(int l, int r, vector<int>& v){
        while(l<r){
            swap(v[l],v[r]);
            l++;
            r--;
        }
    }
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n = arr.size();
        d %= n;
        
        reverse(0,d-1,arr);
        reverse(d,n-1,arr);
        reverse(0,n-1,arr);
    }
};
