class Solution {
public:
    int solve(vector<int>& piles, int turn, int idx, int M,
              vector<vector<vector<int>>>& dp) {
        if (idx >= piles.size()) {
            return 0;
        }

        if (dp[turn][idx][M] != -1) {
            return dp[turn][idx][M];
        }

        int res = (turn == 1) ? -1 : INT_MAX;

        int ans = 0;

        for (int i = 1; i <= min(2 * M, (int)piles.size() - idx); i++) {
            ans += piles[idx + i - 1];

            if (turn == 1) {
                res = max(res, ans + solve(piles, 0, idx + i, max(M, i), dp));
            } else {
                res = min(res, solve(piles, 1, idx + i, max(M, i), dp));
            }
        }
        return dp[turn][idx][M] = res;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(
            2, vector<vector<int>>(101, vector<int>(101, -1)));
        return solve(piles, 1, 0, 1, dp);
    }
};