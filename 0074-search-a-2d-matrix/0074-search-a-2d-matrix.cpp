class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(),c=matrix[0].size();
        int l=0, h=r*c-1;
        while(l<=h){
            int m = l + (h-l)/2;
            if(matrix[m/c][m%c]==target){
                return true;
            }
            else if(matrix[m/c][m%c]<target){
                l= m+1;
            }
            else{
                h=m-1;
            }

        }
        return false;
    }
};