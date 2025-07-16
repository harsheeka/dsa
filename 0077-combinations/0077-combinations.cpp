class Solution {
public:
    void res(vector<vector<int>> &result, vector<int> temp, int index, int &n, int &k){
        if(temp.size()==k){
            result.push_back(temp);
            return;
        }
        for(int i=index; i<=n ;i++){
            temp.push_back(i);
            res(result,temp,i+1,n,k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        res(result,temp,1,n,k);
        return result;
    }
};