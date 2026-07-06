class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj, vector<int>& time,
            vector<int>& dp) {
        if (adj[node].empty()) {
            return time[node];
        }
        if (dp[node] != -1)
            return dp[node];
        int ans = INT_MIN;
        for (auto& it : adj[node]) {
            ans = max(ans, time[node] + dfs(it, adj, time, dp));
        }
        return dp[node] = ans;
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> dp(n, -1);
        for (auto& it : relations) {
            int u = it[0];
            int v = it[1];
            adj[u - 1].push_back(v - 1);
        }

        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, adj, time, dp));
        }
        return ans;
    }
};