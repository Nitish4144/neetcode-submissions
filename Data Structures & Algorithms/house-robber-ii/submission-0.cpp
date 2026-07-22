class Solution {
public:
    int f(int ind,vector<int>& nums,int flag,vector<vector<int>>& dp){
        if(dp[ind][flag] != -1) return dp[ind][flag];
        if(ind>=nums.size() or (flag == 1 and ind == nums.size()-1)) return 0;
        return dp[ind][flag] = max(nums[ind]+ f(ind+2,nums,flag,dp),f(ind+1,nums,flag,dp) ) ;
    }
    int rob(vector<int>& nums) {
        if(nums.size() ==1) return nums[0];
        vector<vector<int>> dp(nums.size()+2,vector<int> (2,-1) );
        
        return max(f(0,nums,1,dp),f(1,nums,0,dp));
    }
};
