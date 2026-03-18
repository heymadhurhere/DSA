class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,
             vector<vector<bool>>& vis, int m, int n, int x, int y, bool& sub) {
        vis[x][y] = true;

        if (grid1[x][y] == 0)
            sub = false;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 and newX < m and newY >= 0 and newY < n and
                !vis[newX][newY] and grid2[newX][newY] == 1) {
                dfs(grid1, grid2, vis, m, n, newX, newY, sub);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] and grid2[i][j] == 1) {
                    
                    bool sub = true;

                    dfs(grid1, grid2, vis, m, n, i, j, sub);

                    if (sub)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};