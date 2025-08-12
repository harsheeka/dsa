class Solution {
public:
    int func(int m, vector<int>& arr) {
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= m) {
                count++;
            }
        }
        return count;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int l = INT_MAX, h = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            l = min(l, nums[i]);
            h = max(h, nums[i]);
        }
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (func(m, nums) >= k)
                l = m + 1;
            else
                h = m - 1;
        }
        return h;

        return -1;
    }
};