class Solution {
public:
    int solve(vector<vector<int>>& dp, int m, int n, int r, int c) {
        if (r < 0 || c < 0) {
            return 0;
        }
        if (r == 0 && c == 0) {
            return 1;
        }
        if (dp[r][c] != 0) return dp[r][c];
        int up = 0, left = 0;
        up += solve(dp, m, n, r - 1, c);
        left += solve(dp, m, n, r, c - 1);
        return dp[r][c] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return solve(dp, m, n, m - 1, n - 1);
    }
};