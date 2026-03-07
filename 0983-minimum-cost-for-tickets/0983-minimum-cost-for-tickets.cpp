class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int idx, vector<int>& dp, int n) {
        if (idx >= days.size()) return 0;

        if (dp[idx] != -1) return dp[idx];

        int cost_day = costs[0] + solve(days, costs, idx + 1, dp, n);

        // cost for week
        int i = idx;
        for (i = idx; i < days.size() && days[i] < days[idx] + 7; i++);
            int cost_week = costs[1] + solve(days, costs, i, dp, n);
        
        // cost for month
        i = idx;
        for (i = idx; i < days.size() && days[i] < days[idx] + 30; i++);
            int cost_month = costs[2] + solve(days, costs, i, dp, n);

        return dp[idx] = min({cost_day, cost_week, cost_month});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return solve(days, costs, 0, dp, n);
    }
};