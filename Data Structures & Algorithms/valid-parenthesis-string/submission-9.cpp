class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        dp[n][0] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int open = 0; open <= n; open++) {

                if (s[i] == '(') {
                    dp[i][open] = (open < n && dp[i + 1][open + 1]);
                }
                else if (s[i] == ')') {
                    dp[i][open] = (open > 0 && dp[i + 1][open - 1]);
                }
                else { // '*'
                    dp[i][open] =
                        dp[i + 1][open] ||
                        (open < n && dp[i + 1][open + 1]) ||
                        (open > 0 && dp[i + 1][open - 1]);
                }
            }
        }

        return dp[0][0];
    }
};