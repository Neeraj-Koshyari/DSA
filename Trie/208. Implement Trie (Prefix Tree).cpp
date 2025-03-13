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
    
    bool search(string word) {
        int n = word.size();

        TrieNode* temp = root;
        for(int i=0;i<n;i++){
            int idx = word[i]-'a';

            if(temp->v[idx] == NULL)    return false;
            temp = temp->v[idx];
        }

        return temp->flag;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();

        TrieNode* temp = root;
        for(int i=0;i<n;i++){
            int idx = prefix[i]-'a';

            if(temp->v[idx] == NULL)    return false;
            temp = temp->v[idx];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
