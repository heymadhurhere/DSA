class Solution {
public:
    bool cycle(vector<vector<int>>& adj, vector<bool>& path, vector<bool>& vis,
               int node, vector<int>& dp) {
        if (dp[node] != -1) {
            return dp[node];
        }
        vis[node] = true;
        path[node] = true;
        for (auto& it : adj[node]) {
            if (!vis[it]) {
                bool ans = cycle(adj, path, vis, it, dp);
                if (ans)
                    return dp[node] = 1;
            } else if (path[it])
                return dp[node] = 1;
        }
        path[node] = false;
        return dp[node] = 0;
    }
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<vector<int>> adj(n);
        for (auto& it : a) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        vector<int> dp(n, -1);
        // if there is cycle, we cannot complete
        vector<bool> path(n, false);
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            bool ans = cycle(adj, path, vis, i, dp);
            if (ans)
                return false;
        }
        return true;
    }
};