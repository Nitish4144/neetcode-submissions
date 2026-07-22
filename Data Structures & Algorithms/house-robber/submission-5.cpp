class Solution {
public:
    int f(int ind,vector<int>& nums,int sum,vector<vector<int>>& dp){
        if(dp[ind][sum] != -1) return dp[ind][sum];
        if (ind>=nums.size()) return sum;
        int tak = f(ind+2,nums,sum+nums[ind],dp);
        int ntak = f(ind+1,nums,sum,dp);
        return dp[ind][sum] = max(tak,ntak);
    }
    int rob(vector<int>& nums) {
        if(nums.size() ==1) return nums[0];
        vector<vector<int>> dp(nums.size()+2,vector<int> (100*nums.size(),-1) );
        return f(0,nums,0,dp);
    }
};
