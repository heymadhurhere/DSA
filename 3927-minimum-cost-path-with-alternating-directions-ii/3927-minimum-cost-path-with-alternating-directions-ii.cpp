class Solution {
public:
    long long solve(int x, int y, int m, int n,
                    vector<vector<vector<long long>>>& dp, long long time,
                    vector<vector<int>>& waitCost) {
        if (x == m - 1 && y == n - 1)
            return (long long)(m * n);
        int parity = time % 2;
        if (dp[x][y][parity] != -1)
            return dp[x][y][parity];
        if (parity == 0) {
            return dp[x][y][parity] = waitCost[x][y] +
                                      solve(x, y, m, n, dp, time + 1, waitCost);
        }
        long long r = LLONG_MAX, d = LLONG_MAX;
        // right
        if (y + 1 < n) {
            long long tmp = solve(x, y + 1, m, n, dp, time + 1, waitCost);
            if (tmp != LLONG_MAX)
                r = tmp + 1LL * (x + 1) * (y + 1);
        }
        // down
        if (x + 1 < m) {
            long long tmp = solve(x + 1, y, m, n, dp, time + 1, waitCost);
            if (tmp != LLONG_MAX)
                d = tmp + 1LL * (x + 1) * (y + 1);
        }
        return dp[x][y][parity] = min(r, d);
    }
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<vector<long long>>> dp(
            m, vector<vector<long long>>(n, vector<long long>(2, -1)));
        return solve(0, 0, m, n, dp, 1, waitCost);
    }
};