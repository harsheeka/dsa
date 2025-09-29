class Solution {
public:
    bool isValid(int r, int c, int m, int n) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }
    int maxDistance(vector<vector<int>>& grid) {
        
        queue<pair<int, int>> q;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        if (q.empty() || q.size() == grid.size() * grid[0].size()) return -1;

        vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int dist = -1;
        while (!q.empty()) {
            int sz = q.size();
            dist++;
            for (int i = 0; i < sz; i++) {
                pair<int, int> x = q.front();
                q.pop();

                for (int i = 0; i < moves.size(); i++) {
                    int nr = x.first + moves[i].first;
                    int nc = x.second + moves[i].second;
                    if (isValid(nr, nc, grid.size(), grid[0].size()) &&
                        !vis[nr][nc]) {
                        q.push({nr, nc});
                        vis[nr][nc] = 1;
                    }
                }
            }
        }
        return dist;
    }
};