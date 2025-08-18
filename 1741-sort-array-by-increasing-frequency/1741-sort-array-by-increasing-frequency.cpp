class Solution {
public:
    static bool cmp(pair<int,int> p1, pair<int,int> p2){
        if(p1.second!=p2.second){
            return p1.second<p2.second;
        }
        return p1.first>p2.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> freq(201,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]+100]++;
        }
        vector<pair<int,int>> vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back({nums[i],freq[nums[i]+100]});
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};