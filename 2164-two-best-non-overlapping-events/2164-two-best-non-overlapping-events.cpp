class Solution {
public:
    int helper(vector<vector<int>>& events, int idx) {
        auto it =
            std::upper_bound(events.begin(), events.end(), idx,
                             [](int newIdx, const vector<int>& event_data) {
                                 return newIdx < event_data[0];
                             });
        return distance(events.begin(), it);
    }
    int solve(vector<vector<int>>& events, int idx, int size, vector<vector<int>>& dp) {
        if (idx >= events.size() || size > 2) {
            return 0;
        }
        if (dp[idx][size] != -1)
            return dp[idx][size];
        int notPick = solve(events, idx + 1, size, dp);
        int pick = 0;
        if (size + 1 <= 2) {
            int newIdx = helper(events, events[idx][1]);
            pick = events[idx][2] + solve(events, newIdx, size + 1, dp);
        }
        return dp[idx][size] = max(pick, notPick);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(begin(events), end(events));
        vector<vector<int>> dp(n + 1, vector<int>(3, -1));
        return solve(events, 0, 0, dp);
    }
};