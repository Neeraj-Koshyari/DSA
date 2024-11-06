// Question Link : https://www.geeksforgeeks.org/problems/root-to-leaf-paths-sum/1

class Solution {
  public:
    int find(Node *root, int val){
        
        val = val*10 + root->data;
        int left = 0, right = 0;
        if(!root->left && !root->right) return val;
        
        if(root->left)  left = find(root->left, val);
        if(root->right) right = find(root->right, val);
        
        return left+right;
    }
    int treePathsSum(Node *root) {
        // code here.
        return find(root,0);
    }
};
