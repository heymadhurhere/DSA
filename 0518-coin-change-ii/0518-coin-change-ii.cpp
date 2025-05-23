class Solution {
public:
    int solve(int idx, int target, vector<int>& coins,
              vector<vector<int>>& dp) {
        if (target == 0) {
            return 1;
        }
        if (idx < 0 || target < 0) {
            return 0;
        }
        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }
        int pick = solve(idx, target - coins[idx], coins, dp);
        int notPick = solve(idx - 1, target, coins, dp);
        return dp[idx][target] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(n - 1, amount, coins, dp);
    }
};