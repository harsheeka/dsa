class Solution {
public:
    int func(vector<vector<int>> &matrix,int k){
        int count=0;
        for(int i=0;i<matrix.size();i++){
            int l=0,h=matrix.size()-1;
            while(l<=h){
                int m = l + (h-l)/2;
                if( matrix[i][m]<=k){
                    l=m+1;
                }
                else{
                     h=m-1;
                }
            }
            count+=l;
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n= matrix.size();
        int l = matrix[0][0], h = matrix[n-1][n-1];
        while(l<=h){
            int m = l + (h-l)/2;
            if(func(matrix,m)<k){
                l=m+1;
            }
            else h=m-1;
        }
        return l;

    }
};