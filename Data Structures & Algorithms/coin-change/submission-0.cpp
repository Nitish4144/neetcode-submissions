class Solution {
public:
    unordered_map<int,int> mp;
    int INF = 1e9;

    int f(int ind,vector<int>& coins, int amount){
        if(amount == 0) return 0;
        if(ind >= coins.size()) return INF;
        if (amount < 0) return INF;
        // if(amount<0 or ind>=coins.size()) return INF;
        return min( 1+f(ind,coins,amount-coins[ind]),f(ind+1,coins,amount) );
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = f(0, coins, amount);
        return ans >= INF ? -1 : ans;
    }
};
