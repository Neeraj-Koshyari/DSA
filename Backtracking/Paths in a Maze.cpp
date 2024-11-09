// Problem Link : https://www.naukri.com/code360/problems/paths-in-a-maze_981287

void find(int i, int j, int n, vector<vector<bool>>& arr, vector<string>& ans, string temp){
    if(i<0 || j<0 || i == n || j == n || !arr[i][j])    return;
    if(i == n-1 && j == n-1){
        ans.push_back(temp);
        return;
    }

    arr[i][j] = false;

    find(i+1,j,n,arr,ans,temp+'D');
    find(i-1,j,n,arr,ans,temp+'U');
    find(i,j+1,n,arr,ans,temp+'R');
    find(i,j-1,n,arr,ans,temp+'L');

    arr[i][j] = true;

}
vector<string> findAllPaths( vector<vector<bool>> &arr)
{
    //    Write your code here.
    int n = arr.size();
    
    vector<string> ans;
    
    find(0,0,n,arr,ans,"");
    return ans;
}
