class Solution {
public:
    void res(vector<vector<int>> &result, vector<int> &nums,int index){
        if(index==nums.size()-1){
            result.push_back(nums);
            return;
        }
        for(int i= index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            res(result,nums,index+1);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        res(result,nums,0);
        return result;
    }
};