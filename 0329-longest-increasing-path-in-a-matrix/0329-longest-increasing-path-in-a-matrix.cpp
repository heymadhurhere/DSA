class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>>& dp,
            vector<vector<int>>& grid) {
        if (dp[i][j] != 0)
            return dp[i][j];

        int maxi = 1;

        // up
        if (i - 1 >= 0 and grid[i - 1][j] > grid[i][j]) {
            maxi = max(maxi, 1 + dfs(i - 1, j, m, n, dp, grid));
        }
        // down
        if (i + 1 < m and grid[i + 1][j] > grid[i][j]) {
            maxi = max(maxi, 1 + dfs(i + 1, j, m, n, dp, grid));
        }
        // left
        if (j - 1 >= 0 and grid[i][j - 1] > grid[i][j]) {
            maxi = max(maxi, 1 + dfs(i, j - 1, m, n, dp, grid));
        }
        // right
        if (j + 1 < n and grid[i][j + 1] > grid[i][j]) {
            maxi = max(maxi, 1 + dfs(i, j + 1, m, n, dp, grid));
        }

        return dp[i][j] = maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j, m, n, dp, grid));
            }
        }
        return ans;
    }
};