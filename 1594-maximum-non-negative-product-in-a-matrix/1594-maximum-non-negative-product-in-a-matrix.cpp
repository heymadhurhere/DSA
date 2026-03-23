class Solution {
public:
    const int MOD = 1e9 + 7;

    pair<long long, long long>
    dfs(int i, int j, vector<vector<int>>& grid,
        vector<vector<pair<long long, long long>>>& dp) {

        if (i == 0 && j == 0) {
            return {grid[0][0], grid[0][0]};
        }

        if (dp[i][j].first != LLONG_MIN)
            return dp[i][j];

        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

        // from top
        if (i > 0) {
            auto [mx, mn] = dfs(i - 1, j, grid, dp);

            long long a = mx * grid[i][j];
            long long b = mn * grid[i][j];

            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        // from left
        if (j > 0) {
            auto [mx, mn] = dfs(i, j - 1, grid, dp);

            long long a = mx * grid[i][j];
            long long b = mn * grid[i][j];

            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        return dp[i][j] = {maxi, mini};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<long long, long long>>> dp(
            m, vector<pair<long long, long long>>(n, {LLONG_MIN, LLONG_MIN}));

        auto [maxProd, minProd] = dfs(m - 1, n - 1, grid, dp);

        if (maxProd < 0)
            return -1;

        return maxProd % MOD;
    }
};