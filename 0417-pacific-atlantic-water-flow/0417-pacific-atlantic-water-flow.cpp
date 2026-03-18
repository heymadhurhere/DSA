class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int x,
             int y, int m, int n, vector<vector<bool>>& tmp) {
        vis[x][y] = true;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 and newX < m and newY >= 0 and newY < n and
                !vis[newX][newY] and heights[newX][newY] >= heights[x][y]) {
                tmp[newX][newY] = true;
                dfs(heights, vis, newX, newY, m, n, tmp);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<bool>> pacific(m, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            pacific[0][i] = true;
        }
        for (int i = 0; i < m; i++) {
            pacific[i][0] = true;
        }

        for (int i = 0; i < n; i++) {
            dfs(heights, vis, 0, i, m, n, pacific);
        }
        for (int i = 0; i < m; i++) {
            dfs(heights, vis, i, 0, m, n, pacific);
        }

        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vis[i][j] = false;
            }
        }

        for (int i = 0; i < n; i++) {
            atlantic[m - 1][i] = true;
        }
        for (int i = 0; i < m; i++) {
            atlantic[i][n - 1] = true;
        }

        for (int i = 0; i < n; i++) {
            dfs(heights, vis, m - 1, i, m, n, atlantic);
        }
        for (int i = 0; i < m; i++) {
            dfs(heights, vis, i, n - 1, m, n, atlantic);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] and atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};