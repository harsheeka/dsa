class Solution {
public:
    void res(vector<vector<int>> &result, vector<int> temp, int index, int target, vector<int> &candidates){
        if(target==0){
            result.push_back(temp);
            return;
        }
        if(target<0 || index == candidates.size()){
            return;
        }
        temp.push_back(candidates[index]);
        res(result,temp,index,target-candidates[index],candidates);
        temp.pop_back();
        res(result,temp,index+1,target,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        res(result,temp,0,target, candidates);
        return result;
    }
};