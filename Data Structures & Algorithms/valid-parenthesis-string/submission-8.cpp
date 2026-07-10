class Solution {
public:
    bool checkValidString(string s) {
        int n =s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return dfs(0, 0, s,dp);
    }

private:
    bool dfs(int i, int open, const string& s,vector<vector<int>>& dp) {
        if (open < 0) return false;
        if(dp[i][open] != -1) return dp[i][open];
        if (i == s.size()) return dp[i][open] = open == 0;

        if (s[i] == '(') {
            return dp[i][open] = dfs(i + 1, open + 1, s,dp);
        } else if (s[i] == ')') {
            return dp[i][open] = dfs(i + 1, open - 1, s,dp);
        } else {
            return dp[i][open]= ( dfs(i + 1, open, s,dp) ||
                   dfs(i + 1, open + 1, s,dp) ||
                   dfs(i + 1, open - 1, s,dp) ) ;
        }
    }
};