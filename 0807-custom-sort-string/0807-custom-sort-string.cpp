class Solution {
public:
    static bool cmp(pair<char,int> p1 , pair<char,int> p2){
        return p1.second<p2.second;
    }
    string customSortString(string order, string s) {
        vector<int> rank(26,-1);
        for(int i=0;i<order.length();i++){
            rank[order[i]-'a']=i;
        }
        vector<pair<char,int>>vec;
        for(int i=0;i<s.length();i++){
            vec.push_back({s[i],rank[s[i]-'a']});
        }
        sort(vec.begin(),vec.end(),cmp);
        string output;
        for(int i=0;i<vec.size();i++){
            output+=vec[i].first;
        }
        return output;

    }
};