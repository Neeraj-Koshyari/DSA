// Problem Link: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/?envType=problem-list-v2&envId=tree&status=SOLVED&difficulty=HARD
// Explaination Link: https://youtu.be/oib-XsjFa-M?si=nG8AB9tst-53n3Uj


// In this problem the parent node is always smaller then child node so simple double for loop ( line 21 - 26 ) will set the ancestor
// But if the parent node is not always smaller then child node then we have to use a dfs from the root node

// void dfs(int u, vector<vector<int>>& adj, int par){
// 	for(int bits = 2; bits<32; bits++){
// 		if(dp[u][bits-1] == -1)	break;
// 		dp[u][bits] = dp[dp[u][bits-1]][bits-1];
// 	}
// 	for(auto& v : adj[u]){
// 		if(v == par)	continue;
// 		dp[v][1] = u;
// 		depth[v] = depth[u] + 1;
// 		dfs(v, adj, u);
// 	}
// }

class TreeAncestor {
public:
    int LOG;
    vector<vector<int>> up;

    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;
        while((1<<LOG) <= n)    LOG++;

        up.resize(n,vector<int>(LOG,-1));

        for(int v = 0; v<n; v++){
            up[v][0] = parent[v];
        }

        for(int j = 1; j<LOG; j++){
            for(int v=0; v<n; v++){
                if(up[v][j-1] != -1)
                up[v][j] = up[up[v][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int j=0; j<LOG && node!=-1; j++){
            if(k & (1<<j))  node = up[node][j];
        }
        return node;
    }
};
