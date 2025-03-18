// Problem Link: https://www.geeksforgeeks.org/problems/shortest-unique-prefix-for-every-word/1
// Solution Link: https://www.youtube.com/watch?v=6smKfa25Jzo

// Creating array of size 26 gives memory limit exceed

class TrieNode{
    public:
    int count;
    unordered_map<int,TrieNode*> child;
    
    TrieNode(){
        count = 0;
    }
};

class Trie{
    private:
    TrieNode* root;
    public:
    Trie(){
        root = new TrieNode();
    }
    
    void add(string& s){
        TrieNode* temp = root;
        
        for(auto& ch: s){
            int idx = ch-'a';
            
            if(temp->child[idx] == NULL)    
                temp->child[idx] = new TrieNode();
                
            temp = temp->child[idx];
            temp->count++;
        }
    }
    
    string find(string& s){
        int n = s.length(), len = 1;
        TrieNode* temp = root;
        
        for(int i=0; i<n; i++){
            int idx = s[i]-'a';
            temp = temp->child[idx];
            
            if(temp->count == 1)   break;
            len++;
        }
        return s.substr(0, len);
    }
    
};

class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        vector<string> ans;
        
        Trie* obj = new Trie();
        for(int i=0; i<n; i++)  obj->add(arr[i]);
        
        for(int i=0; i<n; i++)  ans.push_back(obj->find(arr[i]));
        
        return ans;
    }
    
};
