// Problem Link : https://www.naukri.com/code360/problems/tower-of-hanoi_981323

void TOH(int source, int helper, int destination, vector<vector<int>>& ans, int n) {
    if (n == 1) {
        vector<int> p = {source, destination};  
        ans.push_back(p);
        return;
    }
    TOH(source, destination, helper, ans, n - 1);  
    vector<int> p = {source, destination};
    ans.push_back(p);
    TOH(helper, source, destination, ans, n - 1);  
}
vector<vector<int>> towerOfHanoi(int n) {
    vector<vector<int>> ans;
    TOH(1, 2, 3, ans, n);  
    return ans;

}
