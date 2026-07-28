class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        // Find pivot (minimum element)
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }

        int pivot = l;

        // Decide which half to search
        if (target >= nums[pivot] && target <= nums.back()) {
            l = pivot;
            r = nums.size() - 1;
        } else {
            l = 0;
            r = pivot - 1;
        }

        // Standard binary search
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }
};