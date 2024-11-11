// Problem Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/?envType=problem-list-v2&envId=tree&status=SOLVED

class Solution {
public:
    int ans;
    int find(TreeNode* root){
        if(!root)   return 0;

        int left = find(root->left);
        int right = find(root->right);

        ans = max(ans,left+right+root->val);

        return max(0,root->val + max(left,right));
    }

    int maxPathSum(TreeNode* root) {
        ans = -1e4;
        find(root);
        return ans;
    }
};
