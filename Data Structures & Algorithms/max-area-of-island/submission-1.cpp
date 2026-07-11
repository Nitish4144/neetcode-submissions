class Solution {
public:
    int f(int r,int c, vector<vector<int>>& v,vector<vector<int>>& grid,int ans){
        v[r][c] = 1;
        ans += 1;
        int dr[4] = {0,0,-1,1};
        int dc[4] = {-1,1,0,0};
        queue<pair<int,int>> q; //contains nearby lands

        for(int i =0;i<4;i++){
            int nr = r +dr[i];
            int nc = c +dc[i];
            if(nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size())
                continue;
            if(grid[nr][nc] == 1 and v[nr][nc]!=1) {
                q.push({nr,nc});
            }
        }
        // ans+=q.size();
        while(!q.empty()){
            int nr = q.front().first;
            int nc = q.front().second;
            q.pop(); 
            if(v[nr][nc]) continue;
            ans += f(nr,nc,v,grid,0);
        }

        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int ans =0;
        vector<vector<int>> v(n,vector<int>(m,0));

        for(int r =0;r<n;r++)
        {
            for(int c =0;c<m;c++)
            {
                if(grid[r][c] == 1 and v[r][c]!=1) {
                    // ans =0;
                    ans=max(ans,f(r,c,v,grid,0));
                } 
            }
        }

        return ans;
        
    }
};
