class Solution {
public:
    int dfs(int node, vector<vector<pair<int, int>>>& adj,
            vector<unordered_map<int, unordered_map<int, int>>>& dp, int k,
            int t, int sum, int numEdges) {
        if (sum >= t) {
            return -1;
        }
        if (numEdges == k) {
            return sum;
        }
        if (dp[node].count(numEdges) && dp[node][numEdges].count(sum)) {
            return dp[node][numEdges][sum];
        }
        int ans = -1;
        for (auto it : adj[node]) {
            ans = max(ans, dfs(it.first, adj, dp, k, t, sum + it.second,
                               numEdges + 1));
        }
        dp[node][numEdges][sum] = ans;
        return ans;
    }
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        vector<unordered_map<int, unordered_map<int, int>>> dp(n);
        int res = -1;
        for (int i = 0; i < n; i++) {
            res = max(res, dfs(i, adj, dp, k, t, 0, 0));
        }
        return res;
    }
};