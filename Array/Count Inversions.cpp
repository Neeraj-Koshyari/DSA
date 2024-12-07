// Problem Link: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

class Solution {
  public:
    // Function to count inversions in the array.
    int mergeInversion(int l, int mid, int r, vector<int>& arr){
        int n = mid-l+1, m = r-mid;
        
        vector<int> left(n), right(m);
        for(int i=0;i<n;i++)    left[i] = arr[l+i];
        for(int i=0;i<m;i++)    right[i] = arr[mid+1+i];
        
        int i=0, j=0, k=l, count = 0;
        while(i<n && j<m){
            if(left[i] > right[j]){
                count += (n-i);
                arr[k] = right[j];
                j++;
            }
            else{
                arr[k] = left[i];
                i++;
            }
            k++;
        }
        
        while(i<n){
            arr[k] = left[i];
            i++;
            k++;
        }
        while(j<m){
            arr[k] =right[j];
            j++;
            k++;
        }
        return count;
    }
    
    int inversion(int l, int r, vector<int>& arr){
        if(l<r){
            int mid = (l+r)/2;
            int left = inversion(l,mid,arr);
            int right = inversion(mid+1,r,arr);
            int both = mergeInversion(l,mid,r,arr);
            
            return left+right+both;
        }
        return 0;
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        return inversion(0,n-1, arr);
    }
};
