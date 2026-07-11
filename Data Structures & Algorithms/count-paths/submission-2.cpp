class Solution {
public:
    int f(int r, int c,int& m,int& n,vector<vector<int>>& dp){
        if(r>=m or c>=n) return 0;
        if(r==m-1 and c == n-1 ){
            return dp[r][c] = 1;
           
        }
        if(dp[r][c] != -1) return dp[r][c];
        else{
            dp[r][c] = f(r+1,c,m,n,dp)+f(r,c+1,m,n,dp);
        }
        return dp[r][c];
    }
    int uniquePaths(int m, int n) {
        // long ans =0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // int ans = f(0,0,m,n,dp);
        dp[m-1][n-1] = 1;
        dp[m-1] = vector<int>(n, 1);
        // dp[n-1] = vector<int>(m, 1);
        for(int i =0;i<m;i++) dp[i][n-1]=1;

        for(int r=m-2;r>=0;r--){
            for(int c=n-2;c>=0;c--){
                dp[r][c] = dp[r][c+1] + dp[r+1][c];
            }
        }
        return dp[0][0];
    }
};
