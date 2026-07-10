template <typename T> using vi = vector<T>;
class Solution {
public:
    int ans = INT_MAX;
    void dfs(vector<vector<pair<int, int>>>& adj, int curr, int dst, int k,
             int stops, int cost, vi<int>& minCost, vi<int>& minStop,
             vi<bool>& vis) {
        if (curr == dst) {
            ans = min(ans, cost);
            return;
        }
        if (stops > k)
            return;
        // if present node already vis with less stops and less cost, do not
        // visit it
        if (cost >= minCost[curr] && stops >= minStop[curr]) {
            return;
        }
        minCost[curr] = cost;
        minStop[curr] = stops;
        vis[curr] = true;
        for (auto& it : adj[curr]) {
            int nxt = it.first;
            int wt = it.second;
            if (!vis[nxt] && cost + wt < ans) {
                dfs(adj, nxt, dst, k, stops + 1, cost + wt, minCost, minStop,
                    vis);
            }
        }
        vis[curr] = false;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v, w});
        }

        vector<int> minCost(n, INT_MAX);
        vector<int> minStop(n, INT_MAX);
        vector<bool> vis(n, false);

        dfs(adj, src, dst, k, 0, 0, minCost, minStop, vis);
        return ans == INT_MAX ? -1 : ans;
    }
};