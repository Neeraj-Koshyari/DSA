// Problem Link: https://www.geeksforgeeks.org/problems/maximum-xor-subarray--141631/1
// Solution Link: https://www.youtube.com/watch?v=cHW7DKcheBo

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
    
    void insert(int val){
        TrieNode* temp = root;
        for(int i=31; i>=0; i--){
            int idx = (val>>i)&1;
            
            if(temp->v[idx] == NULL)
                temp->v[idx] = new TrieNode();
                
            temp = temp->v[idx];
        }
    }
    
    int XoR(int val){
        TrieNode* temp = root;
        int ans = 0;
        for(int i=31; i>=0; i--){
            int idx = (val>>i)&1;
            
            if(temp->v[1-idx]){
                ans |= (1<<i);
                temp = temp->v[1-idx];
            }
            else temp = temp->v[idx];
        }
        return ans;
    }
};


class Solution{   
public:
    int maxSubarrayXOR(int N, int arr[]){    
        //code here
        Trie obj;
        int x = 0, ans = 0;
        for(int i=0; i<N; i++){
            x ^= arr[i];
            obj.insert(x);
        }
        
        x = 0;
        for(int i=0; i<N; i++){
            ans = max(ans, obj.XoR(x));
            x ^= arr[i];
        }
        return ans;
    }
};
