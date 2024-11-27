// Problem Link: https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1

// Approch 1:
class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        for(int i=0;i<n;i++){
            while(arr[i] <= n && arr[i] > 0 && arr[i] != i+1 && arr[i] != arr[arr[i] - 1]){
                swap(arr[i],arr[arr[i]-1]);
            }
        }
        
        for(int i=0;i<n;i++){
            if(arr[i] != i+1)   return i+1;
        }
        return n+1;
    }
};



// Approch 2:
class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // Your code here
        int flag = 0, n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i] == 1) flag = 1;
            if(arr[i] > n || arr[i] < 1)    arr[i] = 1;
        }
        
        if(flag == 0)   return 1;
        
        for(int i=0;i<n;i++){
            int idx = abs(arr[i]);
            arr[idx - 1] = -1 * abs(arr[idx - 1]);
        }
        
        for(int i=0;i<n;i++){
            if(arr[i] > 0)  return i+1;
        }
        return n+1;
    }
};
