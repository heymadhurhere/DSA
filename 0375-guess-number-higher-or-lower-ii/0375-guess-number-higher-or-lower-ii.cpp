class Solution {
public:
    int solve(int l, int r, vector<vector<int>>& dp) {
        if (l >= r) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        int res = INT_MAX;
        for (int i = l; i < r; i++) {
            res = min(res, i + max(solve(i + 1, r, dp), solve(l, i - 1, dp)));
        }
        return dp[l][r] = res;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return solve(1, n, dp);
    }
};