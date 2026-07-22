class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,bool> vis;
    bool dfs(int ind, int prev){
        if(vis[ind] == true) return false;
        vis[ind] =true;
        // bool ans = true;
        for(auto& it:adj[ind]){
            if(it==prev) continue;
            if(!dfs(it,ind)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        for(auto& it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
    return ( dfs(0,-1) and (vis.size() == n));
    }
};
