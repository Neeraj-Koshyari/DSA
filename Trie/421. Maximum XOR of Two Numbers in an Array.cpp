// Problem Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
// Solution Link: https://www.youtube.com/watch?v=eB9qHOx_vSw

class TrieNode{
    public:
    vector<TrieNode*> v;
    TrieNode(){
        v.resize(2,NULL);
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(int x){
        TrieNode* temp = root;
        for(int i=31; i>=0; i--){
            int idx = (x>>i) & 1;

            if(temp->v[idx] == NULL)
                temp->v[idx] = new TrieNode();
            
            temp = temp->v[idx];
        }
    }

    int find(int x){
        int ans = 0;
        TrieNode* temp = root;

        for(int i=31; i>=0; i--){
            int idx = (x>>i) & 1;

            if(temp->v[1-idx]){
                ans |= (1<<i);
                temp = temp->v[1-idx];
            }
            else    temp = temp->v[idx];
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie node;
        for(auto& x : nums) node.insert(x);

        int ans = 0;
        for(auto& x : nums) ans = max(ans, node.find(x));

        return ans;
    }
};
