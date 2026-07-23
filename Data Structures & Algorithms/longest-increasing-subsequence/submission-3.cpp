class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;
        int ans  =1;
        arr.push_back(nums[0]);
        for(int i =0;i<nums.size();i++){
            if(nums[i]>arr.back()){
                arr.push_back(nums[i]);
                ans++;
            }
            else{
                int idx = lower_bound(arr.begin(),arr.end(),nums[i]) - arr.begin();
                arr[idx] = nums[i];
            }
        }
        return ans;
    }
};
