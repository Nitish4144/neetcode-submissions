class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int ans = max(nums.being(),nums.end());
        int ans = *max_element(nums.begin(), nums.end());
        int cmax = 1;
        int cmin =1;
        for(auto it:nums){
            int temp = cmax;
            cmax = max(cmax*it,max(cmin*it,it));
            cmin = min(temp*it,min(cmin*it,it));
            ans = max(ans,cmax);
        }
        return ans;
    }
};
