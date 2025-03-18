// Problem Link: https://leetcode.com/problems/longest-word-in-dictionary/description/
// Solution Link: https://www.youtube.com/watch?v=JcVuRZC84y0

// Problem Link: https://leetcode.com/problems/implement-trie-prefix-tree/
// Solution Link: https://www.youtube.com/watch?v=0Y8gwLiQbeE

class TrieNode{
    public:

    vector<TrieNode*> v;
    bool flag;
    TrieNode(){
        v = vector<TrieNode*>(26,NULL);
        flag = false;
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
        }
        temp->flag = true;
    }
    
    string startsWith(string prefix) {
        int n = prefix.size(), len = 0;

        TrieNode* temp = root;
        for(int i=0;i<n;i++){
            int idx = prefix[i]-'a';

            temp = temp->v[idx];
            if(temp == NULL || !temp->flag)    break;
            len++;
        }
        
        return prefix.substr(0, len);
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie node;
        for(auto& x : words)  node.insert(x);

        string ans = "";
        for(auto& x : words){
            string temp = node.startsWith(x);
            int n = ans.size();
            int m = temp.size();

            if(n < m)   ans = temp;
            else if(n == m) ans = min(ans, temp);
        }
        return ans;
    }
};
