class Solution {
public:
    void sub(vector<int>& nums, vector<int>& temp, int level,
             vector<vector<int>>& result) {

        result.push_back(temp);
        for (int i = level; i < nums.size(); i++) {
            if ( i>level && nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            sub(nums, temp, i + 1, result);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        sub(nums, temp, 0, result);
        return result;
    }
};