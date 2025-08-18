class Solution {
public:
    static bool cmp(vector<int> p1, vector<int> p2){
        int d1 =p1[0]*p1[0] + p1[1]*p1[1];
        int d2 = p2[0]*p2[0] + p2[1]*p2[1];
        return d1<d2;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(),points.end(),cmp);
        vector<vector<int>> output;
        for(int i=0;i<k;i++){
            output.push_back(points[i]);
        }
        return output;
    }
};