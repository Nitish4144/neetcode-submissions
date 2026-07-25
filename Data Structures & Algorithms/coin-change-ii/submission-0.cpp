class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> memo(coins.size() + 1,
                            vector<int>(amount + 1,0));

        // return dfs(0, amount, coins, memo);
        int n = coins.size();
        // for(int a =0;a<=amount;a++) memo[n][a] = 0;
        for(int i =0;i<=n;i++){
            memo[i][0] = 1;
        }
        for(int i = n-1;i>=0;i--){
            for(int a = 0;a<=amount;a++){
                // memo[i][a] = memo[i+1][a] + ((a-coins[i])>=0?memo[i][a-coins[i]]:0);
                memo[i][a] = memo[i + 1][a];
                if (a >= coins[i])
                    memo[i][a] += memo[i][a - coins[i]];
            }
            
        }
        return memo[0][amount];
    }

    int dfs(int i, int a, vector<int>& coins, vector<vector<int>>& memo) {
        if (a == 0) return 1;
        if (i >= coins.size()) return 0;
        if (memo[i][a] != -1) return memo[i][a];

        int res = 0;
        if (a >= coins[i]) {
            res = dfs(i + 1, a, coins, memo);
            res += dfs(i, a - coins[i], coins, memo);
        }
        memo[i][a] = res;
        return res;
    }
};