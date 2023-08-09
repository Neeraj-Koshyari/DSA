/*  Question link: https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
    Explanation (by striver) link: https://www.youtube.com/watch?v=q_a6lpbKJdw&ab_channel=takeUforward  */


// gfg solution
vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;
        map<int,vector<int>> mp;
        queue<pair<Node*,int>> qu;
        qu.push({root,0});
        
        while(qu.size()){
            auto pair=qu.front();
            qu.pop();
            auto node=pair.first;
            int val=pair.second;
            
            mp[val].push_back(node->data);
            
            if(node->left)  qu.push({node->left,val-1});
            if(node->right) qu.push({node->right,val+1});
        }
        
        for(auto& x:mp){
            for(auto& y:x.second)
                ans.push_back(y);
        }
        return ans;
}

//leetcode solution same as striver

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> un;

        queue<pair<TreeNode*,pair<int,int>>> qu;
        qu.push({root,{0,0}});
        int level=-1;
        while(qu.size()){
            int n=qu.size();
            while(n--){
                auto pair=qu.front();
                auto node=pair.first;
                int x=pair.second.first;   //vertical_order
                int y=pair.second.second;     //level_order
                qu.pop();
                un[x][y].insert(node->val);

                if(node->left)  qu.push({node->left,{x-1,y+1}});
                if(node->right) qu.push({node->right,{x+1,y+1}});
            }
        }      
        vector<vector<int>> ans;

        for(auto& x:un){
            vector<int> col;
            for(auto& y:x.second)
                col.insert(col.end(),y.second.begin(),y.second.end());
            ans.push_back(col);
        }
        return ans;  
    }
};
