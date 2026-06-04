class Solution {
public:
    const int MOD = 1e9 + 7;
    int dfs(int i, int j, int m, int n, vector<vector<int>>& dp,
            vector<vector<int>>& grid) {
        if (dp[i][j] != 0)
            return dp[i][j];

        int ans = 1;

        // up
        if (i - 1 >= 0 and grid[i - 1][j] > grid[i][j]) {
            ans = (ans + dfs(i - 1, j, m, n, dp, grid)) % MOD;
        }
        // down
        if (i + 1 < m and grid[i + 1][j] > grid[i][j]) {
            ans = (ans + dfs(i + 1, j, m, n, dp, grid)) % MOD;
        }
        // left
        if (j - 1 >= 0 and grid[i][j - 1] > grid[i][j]) {
            ans = (ans + dfs(i, j - 1, m, n, dp, grid)) % MOD;
        }
        // right
        if (j + 1 < n and grid[i][j + 1] > grid[i][j]) {
            ans = (ans + dfs(i, j + 1, m, n, dp, grid)) % MOD;
        }

        return dp[i][j] = ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = (ans + dfs(i, j, m, n, dp, grid)) % MOD;
            }
        }
        return ans;
    }
};