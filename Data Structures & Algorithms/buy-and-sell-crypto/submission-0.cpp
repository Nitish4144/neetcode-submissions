class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int maxi=prices[n-1];
        for(int i =n-1;i>=0;i--){
            if(maxi < prices[i]) maxi = prices[i];
            ans = max(ans,maxi-prices[i]);
        }
        return ans;
    }
};
