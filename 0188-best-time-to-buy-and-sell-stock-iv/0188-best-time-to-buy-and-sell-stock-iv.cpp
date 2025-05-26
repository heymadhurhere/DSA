class Solution {
public:
    int solve(int idx, int buy, vector<int>& prices,
              vector<vector<vector<int>>>& dp, int txns, int k) {
        if (idx == prices.size() || txns == k) {
            return 0;
        }
        if (dp[idx][buy][txns] != -1) {
            return dp[idx][buy][txns];
        }
        int profit = 0;
        if (buy == 1) {
            profit = max(-prices[idx] + solve(idx + 1, 0, prices, dp, txns, k),
                         solve(idx + 1, 1, prices, dp, txns, k));
        } else {
            profit =
                max(prices[idx] + solve(idx + 1, 1, prices, dp, txns + 1, k),
                    solve(idx + 1, 0, prices, dp, txns, k));
        }
        return dp[idx][buy][txns] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k, -1)));
        return solve(0, 1, prices, dp, 0, k);
    }
};