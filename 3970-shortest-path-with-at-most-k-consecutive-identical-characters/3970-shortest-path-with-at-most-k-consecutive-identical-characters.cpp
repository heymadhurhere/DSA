class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        int total = n * (k + 1);
        vector<vector<pair<int, int>>> adj(total);
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            for (int c = 1; c <= k; c++) {
                int from = u * (k + 1) + c;
                if (labels[u] == labels[v]) {
                    if (c + 1 <= k) {
                        int to = v * (k + 1) + (c + 1);
                        adj[from].push_back({to, wt});
                    }
                } else {
                    int to = v * (k + 1) + 1;
                    adj[from].push_back({to, wt});
                }
            }
        }

        vector<int> dist(total, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        // normal dijkistra
        int s = 1;
        dist[s] = 0;
        pq.push({0, s});

        while (!pq.empty()) {
            int d = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            if (d > dist[curr])
                continue;

            for (auto& it : adj[curr]) {
                int nxt = it.first;
                int wt = it.second;

                if (d + wt < dist[nxt]) {
                    dist[nxt] = d + wt;
                    pq.push({dist[nxt], nxt});
                }
            }
        }

        int ans = INT_MAX;
        for (int c = 1; c <= k; c++) {
            int dest = (n - 1) * (k + 1) + c;
            ans = min(ans, dist[dest]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};