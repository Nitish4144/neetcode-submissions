class Solution {
public:
    void dfs(vector<vector<int>>& grid,int r, int c){
        int k =4;
        int dr[] = {0,0,1,-1};
        int dc[] = {-1,1,0,0};
        for(int i = 0;i<k;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(!( nr>=grid.size() or nr<0 or nc>=grid[0].size() or nc<0 )){
                if(grid[nr][nc]>0 and grid[nr][nc] > grid[r][c]+1) 
                    grid[nr][nc]=grid[r][c]+1,dfs(grid,nr,nc);
            }
        } 
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int r =0;r<n;r++){
            for(int c =0;c<m;c++){
                if(grid[r][c] == 0) dfs(grid,r,c);
            }
        }
    }
};
