class Solution {
public:
    static bool cmp(pair<int,int>p1 , pair<int,int>p2){
        if(p1.second == -1 && p2.second == -1){
            return p1.first< p2.first;
        }
        else if(p1.second== -1){
            return false;
        }
        else if(p2.second == -1){
            return true;
        }
            return p1.second<p2.second;
    }
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> rank(1001,-1);
        for(int i=0;i<arr2.size();i++){
            rank[arr2[i]]=i;
        }
        vector<pair<int,int>> vec;
        for(int i=0;i<arr1.size();i++){
            vec.push_back({arr1[i],rank[arr1[i]]});
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<int> output;
        for(int i=0;i<vec.size();i++){
            output.push_back(vec[i].first);
        }
        return output;
    }
};