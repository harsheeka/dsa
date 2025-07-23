class Solution {
public:
    int getIndex(int &i, int &j){
        return (i / 3) * 3 + (j / 3);
    }

    void ss(vector<vector<int>> &rf,vector<vector<int>> &cf,vector<vector<int>> &mf, vector<vector<char>>& board, int i, int j, bool &isFound){
        if(isFound) return;
        if(i==9){
            isFound = true;
            return;
        }
        if(board[i][j]!='.'){
            if(j<8){
                ss(rf,cf,mf,board,i,j+1,isFound);
            }
            else{
                ss(rf,cf,mf,board,i+1,0,isFound);
            }
            return;
        }
        int index = getIndex(i,j);
        for(int k=1;k<=9;k++){
            if(rf[i][k-1]==0 && cf[j][k-1]==0 && mf[index][k-1]==0 && isFound==false){
                rf[i][k-1]++, cf[j][k-1]++, mf[index][k-1]++;
                board[i][j]= k+'0';
                if(j<8){
                ss(rf,cf,mf,board,i,j+1,isFound);
                }
                else{
                ss(rf,cf,mf,board,i+1,0,isFound);
                 }
                if(isFound==false){
                    rf[i][k-1]--, cf[j][k-1]--, mf[index][k-1]--;
                board[i][j]='.';
                }
                
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rf(9,vector<int>(9,0));
        vector<vector<int>> cf(9,vector<int>(9,0));
        vector<vector<int>> mf(9,vector<int>(9,0));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int val = board[i][j]-'0'-1;
                    rf[i][val]++;
                    cf[j][val]++;
                    mf[getIndex(i,j)][val]++;
                }
            }
        }
       
        bool ans= false;
        ss(rf,cf,mf,board,0,0, ans);
        return;
    }
};