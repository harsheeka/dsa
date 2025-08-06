class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        int pivot = 0;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] > nums[nums.size() - 1]) {
                if (m < nums.size() - 1 && nums[m] > nums[m + 1]) {
                    pivot = m;
                    break;
                } else {
                    l = m + 1;
                }
            } else {
                h = m - 1;
            }
        }
        if (l > h) {
            pivot = nums.size() - 1;
        }
        if (pivot == nums.size() - 1 || target >= nums[0]) {
            l = 0;
            h = pivot;
        } else {
            l = pivot + 1;
            h = nums.size() - 1;
        }

        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] > target) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};