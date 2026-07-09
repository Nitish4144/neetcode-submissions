class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0 ;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (high-low)/2 + low ;
            if(nums[mid] == target) return mid;
            else
            {
                if (nums[mid]>target) high-=1;
                else low+=1;
            }
        }
        return -1;
    }
};
