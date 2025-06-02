class Solution {
public:
    int mod = 1e9 + 7;
    int level(vector<vector<int>>& adj, vector<bool>& vis) {
        vis[1] = true;
        int lev = 0;
        queue<pair<int, int>> q;
        q.push({1, 0});
        // {node, level};
        while (!q.empty()) {
            int node = q.front().first;
            int level = q.front().second;
            lev = max(lev, level);
            q.pop();
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = true;
                    q.push({it, level + 1});
                }
            }
        }
        return lev;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n + 1, false);
        int lev = level(adj, vis);
        if (lev == 0)
            return 0;
        int ans = 1;
        for (int i = 1; i < lev; i++) {
            ans = (2 * ans) % mod;
        }
        return ans;
    }
};