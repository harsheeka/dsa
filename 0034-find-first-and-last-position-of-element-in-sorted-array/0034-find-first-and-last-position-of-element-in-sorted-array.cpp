class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int l = 0, h = nums.size() - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] == target) {
                if (m == 0) {
                    res[0] = m;
                    break;
                } else if (nums[m] != nums[m - 1]) {
                    res[0] = m;
                    break;
                } else {
                    h = m - 1;
                }
            } else if (nums[m] > target) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        l = 0, h = nums.size() - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] == target) {
                if (m == nums.size() - 1) {
                    res[1] = m;
                    break;
                } else if (nums[m] != nums[m + 1]) {
                    res[1] = m;
                    break;
                } else {
                    l = m + 1;
                }
            } else if (nums[m] > target) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return res;
    }
};