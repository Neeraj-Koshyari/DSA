// Problem Link: https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/
// Solution Link: https://www.youtube.com/watch?v=GBRlktKHChA

class TrieNode{
    public:

    map<int, TrieNode*> v;
    int count;
    TrieNode(){
        count = 0;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int n = word.size();

        TrieNode* temp = root;

        for(int i=0;i<n;i++){
            int idx = word[i]-'a';
            
            if(temp->v[idx] == NULL)
                temp->v[idx] = new TrieNode();
            
            temp = temp->v[idx];
            temp->count++;
        }
    }
    
    int find(string& s){
        int sum = 0;

        TrieNode* temp = root;
        for(auto& x : s){
            int idx = x-'a';

            temp = temp->v[idx];
            sum += temp->count;
        }

        return sum;
    }
    
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie obj;
        for(auto& x : words)  obj.insert(x);

        vector<int> ans;
        for(auto& x : words) ans.push_back(obj.find(x));
        return ans;
    }
};
