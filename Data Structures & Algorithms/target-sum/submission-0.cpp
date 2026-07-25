class Solution {
public:
    int f(int ind, int target, vector<int>& nums) {
    if (ind == nums.size())
        return target == 0;

    return f(ind + 1, target - nums[ind], nums) +
           f(ind + 1, target + nums[ind], nums);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        return f(0,target,nums);
    }
};
