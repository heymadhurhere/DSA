class Solution {
public:
    int solve(int idx, vector<int>& satisfaction, int time,
              vector<vector<int>>& dp) {
        if (idx >= satisfaction.size()) {
            return 0;
        }
        if (dp[idx][time] != -1) {
            return dp[idx][time];
        }
        int pick = satisfaction[idx] * time +
                   solve(idx + 1, satisfaction, time + 1, dp);
        int notPick = solve(idx + 1, satisfaction, time, dp);
        return dp[idx][time] = max(pick, notPick);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, satisfaction, 1, dp);
    }
};