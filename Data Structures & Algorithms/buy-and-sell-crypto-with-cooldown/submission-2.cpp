class Solution {
public:
    vector<vector<int>> dp;

    int f(int ind, bool buy, vector<int>& prices) {
        if (ind >= prices.size()) return 0;
        if (dp[ind][buy] != -1) return dp[ind][buy];
        if (buy) {
            return dp[ind][buy] = max(
                -prices[ind] + f(ind + 1, false, prices),
                f(ind + 1, true, prices)
            );
        }
        return dp[ind][buy] = max(
            prices[ind] + f(ind + 2, true, prices),
            f(ind + 1, false, prices)
        );
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n + 2, vector<int>(2, -1));
        // return f(0, true, prices);

        dp[n][false] = 0;
        dp[n][true] = 0;
        dp[n+1][true] = 0;
        dp[n+1][false] = 0;

        for(int ind = n-1;ind>=0;ind--){
            for( int buy =0;buy<2;buy++)
                if (buy)dp[ind][buy] = max(-prices[ind] + dp[ind + 1][false],dp[ind+1][true]);
                else dp[ind][buy] = max(prices[ind] + dp[ind+2][true],dp[ind+1][false]);
            }
        return dp[0][true];
    }
};