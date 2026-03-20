class Solution {
public:
    void dfs(vector<vector<int>>& land, vector<vector<bool>>& vis, int x, int y,
             int m, int n, int& r2, int& c2) {
        vis[x][y] = true;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 and newX < m and newY >= 0 and newY < n and
                !vis[newX][newY] and land[newX][newY] == 1) {
                r2 = max(newX, r2);
                c2 = max(newY, c2);
                dfs(land, vis, newX, newY, m, n, r2, c2);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();

        vector<vector<int>> ans;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] and land[i][j] == 1) {
                    int r1 = i, c1 = j, r2 = i, c2 = j;
                    dfs(land, vis, i, j, m, n, r2, c2);
                    ans.push_back({r1, c1, r2, c2});
                }
            }
        }
        return ans;
    }
};