class Solution {
public:
    static bool cmp(pair<int,int> p1, pair<int,int> p2){
        return p1.first>p2.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vec;
        for(int i=0;i<position.size();i++){
            vec.push_back({position[i],speed[i]});
        }
        sort(vec.begin(),vec.end(),cmp);
        int count =0;
        double curr_max = 0;
        for(int i=0;i<speed.size();i++){
            double t = double(target - vec[i].first)/vec[i].second;
            if(t>curr_max){
                count++;
                curr_max=t;
            }
        }
        return count;
    }
};