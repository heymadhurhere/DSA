class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node, vector<bool>& vis) {
        vis[node] = true;

        for (auto& it : adj[node]) {
            if (!vis[it]) {
                dfs(adj, it, vis);
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // iterate from back
        for (int i = n - 1; i >= 0; i--) {
            // remove each edge
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
            adj[v].erase(find(adj[v].begin(), adj[v].end(), u));

            int cnt = 0;
            vector<bool> vis(n + 1, false);

            // count total components
            for (int j = 1; j <= n; j++) {
                if (!vis[j]) {
                    dfs(adj, j, vis);
                    cnt++;
                }
            }
            if (cnt == 1)
                return {u, v};
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};