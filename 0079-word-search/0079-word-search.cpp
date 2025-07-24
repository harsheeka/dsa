class Solution {
public:
    bool isSafe(int i, int j, int &m, int &n){
        if(i>=m || j>=n || i<0 || j<0) return false;
        else return true;
    }
    void res(vector<vector<bool>> &isVis, bool &isFound, vector<vector<char>> &board, string &word, int i, int j, int index, int m, int n){
        if(index==word.length()){
            isFound = true;
            return;
        }
        isVis[i][j]=true;
        if(isSafe(i,j+1,m,n) && !isVis[i][j+1] && !isFound && board[i][j+1]==word[index]){
            res(isVis,isFound,board,word,i,j+1,index+1,m,n);
        }
        if(isSafe(i,j-1,m,n) && !isVis[i][j-1] && !isFound && board[i][j-1]==word[index]){
            res(isVis,isFound,board,word,i,j-1,index+1,m,n);
        }
        if(isSafe(i+1,j,m,n) && !isVis[i+1][j] && !isFound && board[i+1][j]==word[index]){
            res(isVis,isFound,board,word,i+1,j,index+1,m,n);
        }
        if(isSafe(i-1,j,m,n) && !isVis[i-1][j] && !isFound && board[i-1][j]==word[index]){
            res(isVis,isFound,board,word,i-1,j,index+1,m,n);
        }
        isVis[i][j]= false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        bool isFound = false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(!isFound && board[i][j]==word[0]){
                    vector<vector<bool>>isVis(board.size(),vector<bool>(board[0].size(),false));
                    isVis[i][j]=true;
                     res(isVis,isFound,board,word,i,j,1,board.size(),board[0].size());
                }
            }
        }
       
        return isFound;
    }
};