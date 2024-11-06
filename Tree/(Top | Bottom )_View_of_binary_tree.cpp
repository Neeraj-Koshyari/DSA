/* question link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
   Explanation (by striver) link: https://www.youtube.com/watch?v=Et9OCDNvJ78&ab_channel=takeUforward  */

class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        map<int,int> mp;
        queue<pair<Node* ,int>> qu;
        qu.push({root,0});
        
        while(qu.size()){
            auto pair=qu.front();
            auto node=pair.first;
            int val=pair.second;
            qu.pop();
            if(mp[val]==0) mp[val]=node->data;      //for top view;
            // mp[val]=node->data;            //for bottom view;
            
            if(node->left)  qu.push({node->left,val-1});
            if(node->right)    qu.push({node->right,val+1});
        }
        for(auto& x:mp)
            ans.push_back(x.second);
            
        return ans;
    }
};
