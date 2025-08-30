class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int sum = -nums[i];
            int x = i + 1, y = n - 1;

            while (x < y) {
                if (nums[x] + nums[y] < sum) {
                    x++;
                } else if (nums[x] + nums[y] > sum) {
                    y--;
                } else {
                    ans.push_back({nums[i], nums[x], nums[y]});

                    int p1 = nums[x], p2 = nums[y];
                    while (x < y && nums[x] == p1) x++;
                    while (x < y && nums[y] == p2) y--;
                }
            }
        }
        return ans;
    }
};
