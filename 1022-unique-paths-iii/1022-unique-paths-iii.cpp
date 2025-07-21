class Solution {
public:
    bool isSafe(int i, int j , vector<vector<int>> &grid){
        if(i>=grid.size() || j>= grid[0].size() || grid[i][j]==-1 || i<0 || j<0){
            return false;
        } else return true;
    }
    void countPaths(vector<vector<int>> &grid, int &count, int i, int j, vector<vector<bool>> &isVis, int rem){
        if(!isSafe(i,j,grid) || isVis[i][j]) return;
        if(grid[i][j]==2 && rem==0){
            count++;
            return;
        }
        isVis[i][j]=true;
        countPaths(grid,count,i+1,j,isVis, rem-1);
        countPaths(grid,count,i-1,j,isVis, rem-1);
        countPaths(grid,count,i,j+1,isVis, rem-1);
        countPaths(grid,count,i,j-1,isVis, rem-1);
        isVis[i][j]= false;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int count=0;
        int starti,startj;
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    cnt++;
                }
                if(grid[i][j]==1){
                    starti=i,startj=j;
                }
            }
        }
        vector<vector<bool>>isVis(grid.size(),vector<bool> (grid[0].size(),false));
        countPaths(grid,count,starti,startj, isVis,cnt+1);
        return count;
    }
};