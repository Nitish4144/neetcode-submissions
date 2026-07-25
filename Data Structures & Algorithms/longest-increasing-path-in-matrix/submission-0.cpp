class Solution {
public:
    vector<vector<int>> dp;
    int ans =0;
    int f(int r, int c, vector<vector<int>>& matrix) {
    if (dp[r][c] != 0)
        return dp[r][c];
    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};
    int best = 1;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nc >= 0 && nr < matrix.size() && nc < matrix[0].size() && matrix[nr][nc] > matrix[r][c]) {
            best = max(best, 1 + f(nr, nc, matrix));
        }
    }
    return dp[r][c] = best;
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ROW = matrix.size();
        int COL = matrix[0].size();
        dp.assign(ROW,vector<int> (COL,0));
        // return f(0,0,matrix);
        int res =0;
        for(int r =0;r<ROW;r++){
            for(int c =0;c<COL;c++){

                res = max(res,f(r,c,matrix));
            }
        }
        return res;
    }
};
