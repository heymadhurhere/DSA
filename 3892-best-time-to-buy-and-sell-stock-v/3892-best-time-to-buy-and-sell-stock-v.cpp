class Solution {
public:
    long long solve(int idx, int buy, int txns, int k, vector<int>& prices,
              vector<vector<vector<long long>>>& dp) {
        int n = prices.size();
        if (idx == n) {
            if (buy != 0) {
                return -1e12;
            }
            return 0;
        }
        if (dp[idx][buy][txns] != -1)
            return dp[idx][buy][txns];

        long long profit = INT_MIN;

        if (buy == 0) {
            profit = solve(idx + 1, 0, txns, k, prices, dp);
            if (txns < k) {
                long long purch =
                    -prices[idx] + solve(idx + 1, 1, txns, k, prices, dp);
                long long shortSell =
                    prices[idx] + solve(idx + 1, 2, txns, k, prices, dp);
                profit = max({purch, shortSell, profit});
            }
        } else if (buy == 1) {
            long long sell = prices[idx] + solve(idx + 1, 0, txns + 1, k, prices, dp);
            long long leave = solve(idx + 1, 1, txns, k, prices, dp);
            profit = max(sell, leave);
        } else {
            long long buyAgain =
                -prices[idx] + solve(idx + 1, 0, txns + 1, k, prices, dp);
            long long leave = solve(idx + 1, 2, txns, k, prices, dp);
            profit = max(buyAgain, leave);
        }
        return dp[idx][buy][txns] = profit;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(3, vector<long long>(k + 1, -1)));
        return solve(0, 0, 0, k, prices, dp);
    }
};