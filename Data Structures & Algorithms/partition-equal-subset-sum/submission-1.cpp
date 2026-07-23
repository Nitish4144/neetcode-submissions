class Solution {
public:
    unordered_map<int,bool> dp;
    bool f(int ind, vector<int>& nums, int sum1, int sum2){
        if(ind>= nums.size() ) return sum1 == sum2;
        if(dp.find(sum1) != dp.end()) return dp[sum1];
        return dp[sum1] = f(ind+1,nums,sum1+nums[ind],sum2) or f(ind+1,nums,sum1,sum2+nums[ind]);
    }
    bool canPartition(vector<int>& nums) {
        int sum1 =0;
        int sum2 =0 ;

        return f(0,nums,sum1,sum2);
    }
};
