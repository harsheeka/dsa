class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;

        // Edge case: only one element
        if (nums.size() == 1) return nums[0];

        while (l <= h) {
            int m = l + (h - l) / 2;

            // Handle boundary cases
            if (m == 0) {
                if (nums[m] != nums[m + 1]) return nums[m];
                else l = m + 1;
            } else if (m == nums.size() - 1) {
                if (nums[m] != nums[m - 1]) return nums[m];
                else h = m - 1;
            }
            // Middle elements
            else if (nums[m] != nums[m + 1] && nums[m] != nums[m - 1]) {
                return nums[m];
            } else {
                int f, s;
                if (nums[m] == nums[m + 1]) {
                    f = m; s = m + 1;
                } else {
                    f = m - 1; s = m;
                }
                if (f % 2 == 0) l = m + 1;
                else h = m - 1;
            }
        }

        return -1; // Should never reach here if input is valid
    }
};
