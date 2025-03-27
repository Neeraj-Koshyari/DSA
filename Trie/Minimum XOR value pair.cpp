// Problem Link: https://www.geeksforgeeks.org/problems/minimum-xor-value-pair/0


//   Method 1: Trie
//   Method 2: Sort and xor adjacent element

class TrieNode{
    public:
    vector<TrieNode*> v;

    TrieNode(){
        v.resize(2, NULL);
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }

    void insert(int n){
        TrieNode* temp = root;
        for(int bits = 31; bits>=0; bits--){
            int idx = (n>>bits) & 1;
            if(temp->v[idx] == NULL)
                temp->v[idx] = new TrieNode();
            temp = temp->v[idx];
        }
    }

    int minXor(int n){
        int ans = 0;
        TrieNode* temp = root;
        for(int bits = 31; bits>=0; bits--){
            int idx = (n>>bits) & 1;

            if(temp->v[idx])    temp = temp->v[idx];
            else{
                temp = temp->v[1-idx];
                ans |= (1<<bits);
            }
        }
        return ans;
    }
};

class Solution{   
public:
    int minxorpair(int N, int arr[]){    
        //code here
        Trie obj;
        obj.insert(arr[0]);
        
        int ans = 1e9;
        for(int i=1;i<N;i++){
            ans = min(ans, obj.minXor(arr[i]));
            obj.insert(arr[i]);
        }
        return ans;
    }
};
