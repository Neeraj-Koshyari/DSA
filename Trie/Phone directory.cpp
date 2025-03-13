// Problem Link: https://www.geeksforgeeks.org/problems/phone-directory4628/1
// Solution Link: https://www.youtube.com/watch?v=WafalqRuXJs


// ****************    Brute Force    ************** (optimal at line 80 )

// TC O( s.length * n * compare each substring )
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


// TC:  O ( ( nLOG(n) * max|contact[i] ) + ( n * max|contact[i] ) + ( |s| * n * max|contact[i] ) ) = |s| * n * max|contact[i]


// User function Template for C++

class TrieNode{
public:
    TrieNode *children[26];
    bool isEnd = false;
    vector<int> ids;
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {       
        root = new TrieNode();
    }
    
    void insert(string word, int id) {
        TrieNode *node = root;
        for(auto& ch : word){
            int idx = ch-'a';
            if(!node->children[idx]){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
            node->ids.push_back(id);
        }
        node->isEnd = true;
    }
    
    vector<vector<string>> startsWith(string s, int n, string contact[]) {
        vector<vector<string>> ans(n);
        
        TrieNode *node = root;
        int i = 0;
        for( ; i<n; i++){
            int idx = s[i] - 'a';
            if(!node->children[idx])    break;
            node = node->children[idx];
            for(auto& x : node->ids)   ans[i].push_back(contact[x]);
        }
        while(i<n){
            ans[i].push_back("0");
            i++;
        }
        
        return ans;
    }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        sort(contact, contact+n);
        Trie obj;
        
        obj.insert(contact[0], 0);
        for(int i=1;i<n;i++){
            if(contact[i-1] != contact[i])  obj.insert(contact[i], i);
        }
        
        return obj.startsWith(s, s.length(), contact);
    }
};
