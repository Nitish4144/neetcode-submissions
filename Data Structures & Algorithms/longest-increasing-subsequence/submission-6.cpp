class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,1);
        // v[n-1] = 1;
        int ans = 0;
        for(int i = n-1;i>=0;i--){
            int res = 0;
            for(int j = i+1;j<n;j++){
                if(nums[j]>nums[i]) res = max(res, 1+v[j]);
            }
            v[i] = res;
            ans = max ( ans , res);
        }
        return 1+ans; 
    }
};
