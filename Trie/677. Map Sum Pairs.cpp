// Problem Link: https://leetcode.com/problems/map-sum-pairs/description/
// Solution Link: https://www.youtube.com/watch?v=wIKu4K5wwqE


class TrieNode{
public:
    vector<TrieNode*> child;
    int count;

    TrieNode(){
        child.resize(26,NULL);
        count = 0;
    }
};

class MapSum {
public:
    TrieNode* root;
    map<string,int> mp;
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        int temp = val - mp[key];
        mp[key] = val;
        val = temp;

        TrieNode *node = root;
        for(auto& ch : key){
            int idx = ch-'a';

            if(!node->child[idx]){
                node->child[idx] = new TrieNode();
            }

            node = node->child[idx];
            node->count += val;
        }
    }
    
    int sum(string prefix) {
        TrieNode* node = root;
        for(auto& ch : prefix){
            int idx = ch-'a';
            node = node->child[idx];
            if(!node)   return 0;
        }
        return node->count;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
