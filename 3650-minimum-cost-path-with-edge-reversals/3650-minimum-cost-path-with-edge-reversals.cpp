class Solution {
public:
    int solve(vector<vector<pair<int, int>>>& adj, int src, int dest, int n) {
        vector<int> dist(n, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int cost = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (cost > dist[u]) {
                continue;
            }

            if (u == dest)
                return cost;

            for (auto& it : adj[u]) {
                int v = it.first;
                int w = it.second;

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[dest] == INT_MAX ? -1 : dist[dest];
    }
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, 2 * wt});
        }

        int ans = solve(adj, 0, n - 1, n);
        return ans;
    }
};