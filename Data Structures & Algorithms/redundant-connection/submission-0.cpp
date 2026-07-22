class Unionjoin{
    public:
    vector<int> parent;
    vector<int> size;
        Unionjoin(int n ){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i =0;i<=n;i++){
                parent[i]=i;
            }
        }

        int findpar(int u){
            if( parent[u] == u)
                return u;
            else
                return parent[u] = findpar(parent[u]);
        }

        void join(int u, int v){
            int ultpu = findpar(u);
            int ultpv = findpar(v);
            if(size[ultpu]<size[ultpv]){
                parent[ultpu] = ultpv;
                size[ultpv]+=size[ultpu];
            }
            else {
                parent[ultpv] = ultpu;
                size[ultpu]+=size[ultpv];
            }
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans(2,0);
        Unionjoin uj(edges.size());
        for(int i =0;i<edges.size();i++){
            if( uj.findpar(edges[i][0]) != uj.findpar(edges[i][1]) )  uj.join(edges[i][0],edges[i][1]);
            else ans = edges[i];
        }
        return ans;
    }
};
