class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> res;
        for(int i=0;i<mat.size();i++){
            int sum=0;
            int l=0,h=mat[0].size()-1;
            while(l<=h){
                int m = l + (h-l)/2;
                if(mat[i][m]==1){
                    if(m==mat[0].size()-1){
                        sum=mat[0].size();
                        break;
                    }
                    else if(mat[i][m+1]!=1){
                        sum= m+1;
                        break;
                    }
                    else{
                        l = m+1;
                    }
                }
                else if(mat[i][m]==0){
                    h=m-1;
                }
            }
            res.push_back({sum,i});
        }
        sort(res.begin(),res.end());
        vector<int > out ;
        for(int i=0;i<k;i++){
            out.push_back(res[i].second);
        }
        return out;
    }
};