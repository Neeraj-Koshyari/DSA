// Problem Link: https://www.geeksforgeeks.org/problems/maximum-xor-with-an-element-from-array/1
// Solution Link: https://www.youtube.com/watch?v=sKlN6PsARbY


#define ll long long
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
    
    void insert(ll x){
        TrieNode* temp = root;
        for(int bits = 31; bits>=0; bits--){
            int idx = (x>>bits)&1;
            if(temp->v[idx] == NULL)
                temp->v[idx] = new TrieNode();
                
            temp = temp->v[idx];
        }
    }
    
    ll find(ll x){
        TrieNode* temp = root;
        ll ans = 0;
        for(int bits = 31; bits>=0; bits--){
            int idx = (x>>bits)&1;
            
            if(temp->v[1-idx]){
                ans |= (1ll<<bits);
                temp = temp->v[1-idx];
            }
            else temp = temp->v[idx];
        }
        return ans;
    }
};

bool cmp(vector<int>& x, vector<int>& y){
    return x[1] < y[1];
}

class Solution {
  public:
    vector<long long> maximumXor(int N, int Q, vector<int> &arr,
                                 vector<vector<int>> &queries) {
        // code here
        sort(arr.begin(),arr.end());
        vector<pair<int,pair<int,int>>> q;
        for(int i=0;i<Q;i++){
            q.push_back({queries[i][1],{queries[i][0],i}});
        }
        
        sort(q.begin(),q.end());
        
        vector<ll> ans(Q);
        Trie* obj = new Trie();
        
        int idx = 0;
        for(int i=0;i<Q;i++){
            ll x = q[i].second.first;
            ll m = q[i].first;
            int index = q[i].second.second;
            
            while(idx < N && arr[idx] <= m){
                obj->insert(arr[idx]);
                idx++;
            }
            
            if(idx == 0)    ans[index] = -1;
            else ans[index] = obj->find(x);
        }
        return ans;
    }
};
