class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int x, int y,
             int m, int n) {
        vis[x][y] = true;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 and newX < m and newY >= 0 and newY < n and
                !vis[newX][newY] and grid[newX][newY] == 1) {
                dfs(grid, vis, newX, newY, m, n);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // first ans last row
        for (int col = 0; col < n; col++) {
            // first row
            if (grid[0][col] == 1) {
                q.push({0, col});
                vis[0][col] = true;
                grid[0][col] = 0;
            }
            // last row
            if (grid[m - 1][col] == 1) {
                q.push({m - 1, col});
                vis[m - 1][col] = true;
                grid[m - 1][col] = 0;
            }
        }

        // first and last col except first and last row
        for (int row = 1; row < m - 1; row++) {
            // first col
            if (grid[row][0] == 1) {
                q.push({row, 0});
                vis[row][0] = true;
                grid[row][0] = 0;
            }
            // last col
            if (grid[row][n - 1] == 1) {
                q.push({row, n - 1});
                vis[row][n - 1] = true;
                grid[row][n - 1] = 0;
            }
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 and newX < m and newY >= 0 and newY < n and
                    !vis[newX][newY] and grid[newX][newY] == 1) {
                    vis[newX][newY] = true;
                    grid[newX][newY] = 0;
                    q.push({newX, newY});
                }
            }
        }

        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, vis, i, j, m, n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};