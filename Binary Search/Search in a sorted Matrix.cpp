// Problem Link: https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1

class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size(), m = mat[0].size();
        int top = -1, bottom = n;
        
        while(top + 1 < bottom){
            int mid = (top + bottom)/2;
            
            if(mat[mid][m-1] >= x)  bottom = mid;
            else top = mid;
        }
        
        int i = bottom;
        if(i == n || x < mat[i][0]) return false;
        
        int left = -1, right = m;
        while(left + 1 < right){
            int mid = (left+right)/2;
            
            if(mat[i][mid] >= x)    right = mid;
            else left = mid;
        }
        int j = right;
        
        if(j == m || mat[i][j] != x)    return false;
        return true;
    }
};
