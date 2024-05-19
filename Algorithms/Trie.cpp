class TrieNode{
public:
    TrieNode *children[26];
    bool isEnd = false;
};

class Trie {
private:
    TrieNode *root = new TrieNode();
public:
    Trie() {        
    }
    
    void insert(string word) {
        TrieNode *node = root;
        for(auto& ch : word){
            int idx = ch-'a';
            if(!node->children[idx]){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *node = root;
        for(auto& ch : word){
            int idx = ch-'a';
            if(!node->children[idx])    return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(auto& ch : prefix){
            int idx = ch-'a';
            if(!node->children[idx])    return false;
            node = node->children[idx];
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
