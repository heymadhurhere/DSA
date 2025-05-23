class Solution {
public:
    int solve(int idx, int amt, vector<int>& coins, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (amt % coins[idx] == 0) {
                return amt / coins[idx];
            }
            return 1e9;
        }
        if (dp[idx][amt] != -1) {
            return dp[idx][amt];
        }
        int notPick = solve(idx - 1, amt, coins, dp);
        int pick = INT_MAX;
        if (coins[idx] <= amt) {
            pick = 1 + solve(idx, amt - coins[idx], coins, dp);
        }
        return dp[idx][amt] = min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(n - 1, amount, coins, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};