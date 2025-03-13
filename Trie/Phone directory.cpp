// Problem Link: https://www.geeksforgeeks.org/problems/phone-directory4628/1
// Solution Link: https://www.youtube.com/watch?v=WafalqRuXJs

class TrieNode{
public:
    TrieNode *children[26];
    bool isEnd = false;
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {       
        root = new TrieNode();
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

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        int m = s.length();
        Trie obj;
        obj.insert(s);
        
        vector<vector<string>> ans(m);
        for(int i=0;i<m;i++){
            set<string> st;
            for(int j=0;j<n;j++){
                if(contact[j].size() < (i+1))   continue;
                string temp = contact[j].substr(0,i+1);
                if(obj.startsWith(temp))    st.insert(contact[j]);
            }
            if(st.size() == 0)  st.insert("0");
            for(auto& x: st)    ans[i].push_back(x);
        }
        return ans;
    }
};
