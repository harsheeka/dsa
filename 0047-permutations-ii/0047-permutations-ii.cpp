class Solution {
public:
    void res(vector<vector<int>> &result, vector<int> &nums, int index){
        if(index==nums.size()-1){
            result.push_back(nums);
            return;
        }
        vector<int> freq(21,0);
        for(int j=index;j<nums.size();j++){
            if(freq[nums[j]+10]==0){
                swap(nums[index],nums[j]);
                res(result,nums,index+1);
                swap(nums[index],nums[j]);
            }
            freq[nums[j]+10]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        res(result,nums,0);
        return result;
    }
};