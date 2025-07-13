class Solution {
public:

    void sub(vector<int>&nums, vector<int>&temp,int level, vector<vector<int>> &result){
        if(level==nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[level]);
        sub(nums,temp,level+1,result);
        temp.pop_back();
        sub(nums,temp,level+1,result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int>temp;
        sub(nums,temp,0,result);
        return result;
    }
};