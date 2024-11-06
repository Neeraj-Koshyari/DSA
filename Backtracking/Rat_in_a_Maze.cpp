/* Question Link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1 */

class Solution{
    public:
    void find_ans(vector<vector<int>> m, int i, int j, int n, string s,vector<string>& ans){
      //no reference calling to m and s which will help in backtracking
        if(i==(n-1) && j==(n-1) && m[i][j]==1){
            ans.push_back(s);
            return;
        }
        
        if(i<0 || j<0 || i>=n || j>=n)
            return;
            
        if(m[i][j]==0)
            return;
            
        m[i][j]=0;    //reamain unchange after returning same for string s

        //all 4 possible directions
        find_ans(m,i-1,j,n,s+'U',ans);
        find_ans(m,i,j-1,n,s+'L',ans);
        find_ans(m,i+1,j,n,s+'D',ans);
        find_ans(m,i,j+1,n,s+'R',ans);
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0)  //if first value is 0 than rat cant move to any other place 
            return {"-1"};
            
        vector<string> ans;
        string s;
        find_ans(m,0,0,n,s,ans);
        
        if(ans.size()==0)  //if no path finded
            return {"-1"};
            
        return ans;
    }
};
