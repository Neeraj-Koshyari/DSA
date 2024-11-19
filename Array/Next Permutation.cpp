// Problem Link: https://www.geeksforgeeks.org/problems/next-permutation5226/1

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int idx = n-2;
        while(idx >= 0 && arr[idx] >= arr[idx+1])    idx--;
        
        if(idx != -1){
            int i = n-1;
            while(arr[idx] >= arr[i])    i--;
            
            swap(arr[idx],arr[i]);
        }
        
        reverse(arr.begin()+idx+1,arr.end());
    }
};
