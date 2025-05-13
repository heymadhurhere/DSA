class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // adjacency list bnao
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];
            adj[u].push_back({v, wt});
        }
        // distance array bnao
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;
        q.push({k, 0});

        // apply dijkstra
        while (!q.empty()) {
            auto it = q.top();
            q.pop();
            int u = it.first;
            for (auto itr : adj[u]) {
                int v = itr.first;
                int cost = itr.second;
                if (dist[v] > dist[u] + cost) {
                    dist[v] = dist[u] + cost;
                    q.push({v, dist[v]});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) {
                return -1;
            } else {
                ans = max(ans, dist[i]);
            }
        }
        return ans;
    }
};