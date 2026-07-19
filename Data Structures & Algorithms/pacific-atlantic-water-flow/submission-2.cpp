class Solution {
public:
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<bool>>& vis) {
        vis[r][c] = true;

        int n = heights.size();
        int m = heights[0].size();

        for (auto &d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                continue;

            if (vis[nr][nc])
                continue;

            // Reverse flow
            if (heights[nr][nc] >= heights[r][c])
                dfs(nr, nc, heights, vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // Pacific (top row + left column)
        for (int i = 0; i < n; i++)
            dfs(i, 0, heights, pacific);

        for (int j = 0; j < m; j++)
            dfs(0, j, heights, pacific);

        // Atlantic (bottom row + right column)
        for (int i = 0; i < n; i++)
            dfs(i, m - 1, heights, atlantic);

        for (int j = 0; j < m; j++)
            dfs(n - 1, j, heights, atlantic);

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};