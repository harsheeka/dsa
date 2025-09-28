class Solution {
public:
    struct Cell{
        int row, col;
    };

    bool isValid(int r,int c,int n,int m){
        return r>=0 && r<n && c>=0 && c<m;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<Cell> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                if(mat[i][j]==1){
                    mat[i][j]=-1;
                }
            }
        }
        vector<pair<int,int>> moves = {{-1,0},{0,-1},{0,1},{1,0}};

        while(!q.empty()){
            Cell x = q.front();
            q.pop();

            for(int i=0;i<moves.size();i++){
                int nr = x.row + moves[i].first;
                int nc = x.col + moves[i].second;

                if(isValid(nr,nc,n,m) && mat[nr][nc]==-1){
                q.push({nr,nc});
                mat[nr][nc]=mat[x.row][x.col]+1;
            }
            }
        }

        return mat;

    }
};