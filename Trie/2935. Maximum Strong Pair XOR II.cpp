// Problem Link: https://leetcode.com/problems/maximum-strong-pair-xor-ii/description/

class TrieNode{
    public:
    vector<TrieNode*> v;
    int count;
    TrieNode(){
        v.resize(2,NULL);
        count = 0;
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
        for(int bits = 31; bits>=0; bits--){
            int idx = (x>>bits)&1;
            if(temp->v[idx] == NULL)
                temp->v[idx] = new TrieNode();
                
            temp = temp->v[idx];
            temp->count++;
        }
    }

    void remove(int x){
        TrieNode* temp = root, *prev = NULL;
        for(int bits = 31; bits>=0; bits--){
            int idx = (x>>bits)&1;

            // if(prev != NULL && prev->count == 0)    delete prev;
            temp = temp->v[idx];
            temp->count--;
            prev = temp;
        }
        // if(prev != NULL && prev->count == 0)    delete prev;
    }
    
    int find(int x){
        TrieNode* temp = root;
        int ans = 0;
        for(int bits = 31; bits>=0; bits--){
            int idx = (x>>bits)&1;
            
            if(temp->v[1-idx] && temp->v[1-idx]->count != 0){
                ans |= (1<<bits);
                temp = temp->v[1-idx];
            }
            else temp = temp->v[idx];
        }
        return ans;
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int ans = 0, n = nums.size();
        sort(nums.rbegin(),nums.rend());

        Trie obj;
        int idx = 0;
        for(int i=0; i<n; i++){
            while(idx < n && abs(nums[idx] - nums[i]) <= nums[idx]){
                obj.insert(nums[idx]);
                idx++;
            }

            ans = max(ans, obj.find(nums[i]));
            obj.remove(nums[i]);
        }
        return ans;
    }
};
