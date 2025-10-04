class Solution {
public:
    
    void dfs2(int i, int j , vector<vector<char>> &board, vector<vector<int>> &vis){
        if(i<0 || i>=board.size() || j<0 || j>= board[0].size() || vis[i][j]==1 || board[i][j]=='X'){
            return;
        }
        vis[i][j]=1;
        board[i][j]='A';
        dfs2(i+1,j,board,vis);
        dfs2(i-1,j,board,vis);
        dfs2(i,j+1,board,vis);
        dfs2(i,j-1,board,vis);
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>> vis1(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==m-1 || j==n-1 || i==0 || j==0){
                    if(board[i][j]=='O'){
                        dfs2(i,j,board,vis1);
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='A'){
                    board[i][j]='O';
                }
            }
        }
        return;
    }
};