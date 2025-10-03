class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return i>=0 && i<m && j<n && j>=0;
    }
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    void dfs (int i,int j, vector<vector<char>> &grid){
        if(!isValid(i,j,grid.size(),grid[0].size()) || grid[i][j]!='1'){
            return ;
        }
        grid[i][j]='0';
        for(int k=0;k<dir.size();k++){
            dfs(i+dir[k].first,j+dir[k].second,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans++;
                     dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};