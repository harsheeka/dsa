class Solution {
public:
    void res(vector<vector<int>>& result, vector<int>& temp, int& k, int index,
             int n) {
        if (temp.size() == k) {
            if (n == 0) {
                result.push_back(temp);
            }
            return;
        }
        for (int i = index; i <= 9; i++) {
            if(i>n) break;
            temp.push_back(i);
            res(result, temp, k, i + 1, n - i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;
        res(result, temp, k, 1, n);
        return result;
    }
};