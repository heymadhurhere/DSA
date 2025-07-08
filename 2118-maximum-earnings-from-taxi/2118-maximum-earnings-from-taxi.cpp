class Solution {
public:
    int helper(vector<vector<int>>& events, int idx) {
        auto it =
            std::upper_bound(events.begin(), events.end(), idx,
                             [](int newIdx, const vector<int>& event_data) {
                                 return newIdx <= event_data[0];
                             });
        return distance(events.begin(), it);
    }
    long long solve(vector<vector<int>>& rides, int idx, int pnt,
                    vector<long long>& dp) {
        if (idx >= rides.size())
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        long long notPick = solve(rides, idx + 1, pnt, dp);
        long long pick = 0;
        if (pnt <= rides[idx][0]) {
            int newIdx = helper(rides, rides[idx][1]);
            pick = rides[idx][1] - rides[idx][0] + rides[idx][2] +
                   solve(rides, newIdx, rides[idx][1], dp);
        }
        return dp[idx] = max(pick, notPick);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        int p = rides.size();
        vector<long long> dp(p + 1, -1);
        return solve(rides, 0, 0, dp);
    }
};