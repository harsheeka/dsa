class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonal =0, maxArea=0;
        for(int i=0;i<dimensions.size();i++){
            for(int j=0;j<2;j++){
                int curr = dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1];
                if(curr>maxDiagonal){
                    maxDiagonal = curr;
                    maxArea = dimensions[i][0]*dimensions[i][1];
                }
                else if(curr == maxDiagonal){
                    maxArea = max(maxArea, dimensions[i][0]*dimensions[i][1]);
                }
            }
        }
        return maxArea;
    }
};