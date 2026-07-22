class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,bool> vis;
    void dfs(int ind,int prev){
        vis[ind] = true;
        for(auto& it:adj[ind]){
            if(it == prev) continue;
            if(vis[it] == false) dfs(it,ind);
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        if(n == 1) return 1;
        for(auto& it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int ans =0;

        for(int i=0;i<n;i++){
            if(vis[i] == false){
                ans+=1;
                dfs(i,-1);
            }
        }
        return ans;
    }
};