class Solution {
public:
    bool isSafe(int &i, int &j, vector<string> &temp, int &n){
        for(int y = i-1; y>=0;y--){
            if(temp[y][j]=='Q') return false;
        }
        for(int x = i-1, y= j-1; x>=0 && y>=0; x--,y--){
            if(temp[x][y]=='Q') return false;
        }
        for(int x = i-1, y= j+1; x>=0 && y<n; x--,y++){
            if(temp[x][y]=='Q') return false;
        }
        return true;
    }
    void res(vector<vector<string>> &result, vector<string> &temp , int row, int &n){
        if(row==n){
            result.push_back(temp);
            return;
        }
        for(int col=0;col<n;col++){
            temp[row][col]='Q';
            if(isSafe(row,col,temp,n)){
                res(result,temp,row+1,n);
            }
            temp[row][col]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n, string(n,'.')) ;
        vector<vector<string>> result;
        res(result,temp,0,n);
        return result;
    }
};