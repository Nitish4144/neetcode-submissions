class Solution {
public:
    unordered_map<int,int> mp;
    vector<vector<int>> dp;
    int INF = 1e9;

    int f(int ind,vector<int>& coins, int amount){
        if(ind >= coins.size() or amount < 0) return INF;
        if(amount == 0) return dp[ind][amount] =  0;
        if(dp[ind][amount] != -1) return dp[ind][amount];
        return dp[ind][amount] = min( 1+f(ind,coins,amount-coins[ind]),f(ind+1,coins,amount) );
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size()+1,vector<int> (amount+1,-1));
        int ans = f(0, coins, amount);
        return ans >= INF ? -1 : ans;
    }
};
