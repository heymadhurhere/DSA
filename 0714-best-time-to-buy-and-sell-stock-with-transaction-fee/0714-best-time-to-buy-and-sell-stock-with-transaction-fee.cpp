
class Solution {
public:
    int solve(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp,
              int fee) {
        if (idx == prices.size()) {
            return 0;
        }
        if (dp[idx][buy] != -1) {
            return dp[idx][buy];
        }
        int profit = INT_MIN;
        if (buy == 1) {
            profit = max(-prices[idx] + solve(idx + 1, 0, prices, dp, fee),
                         solve(idx + 1, 1, prices, dp, fee));
        } else {
            profit = max(prices[idx] + solve(idx + 1, 1, prices, dp, fee) - fee,
                         solve(idx + 1, 0, prices, dp, fee));
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(0, 1, prices, dp, fee);
    }
};