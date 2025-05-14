class Solution {
public:
    void dfs(int node, vector<bool>& vis, vector<vector<int>>& adj) {
        vis[node] = true;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if (edges < n - 1) {
            return -1;
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj);
                cnt++;
            }
        }
        if (cnt == 1) {
            return 0;
        }
        return cnt - 1;
    }
};