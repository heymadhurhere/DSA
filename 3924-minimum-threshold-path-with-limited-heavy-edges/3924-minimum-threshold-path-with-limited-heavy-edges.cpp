class Solution {
public:
    int solve(vector<vector<pair<int, int>>>& adj, int source, int target) {
        vector<int> dis(adj.size(), 1e9);
        dis[source] = 0;
        // priority_queue<pair<int, int>, vector<pair<int, int>>,
        // greater<pair<int, int>>> pq;
        set<pair<int, int>> pq;
        pq.insert(
            {dis[source], source}); // we need orderinig by distance so the
                                    // distance should be inserted first
        while (!pq.empty()) {
            auto itr = *pq.begin();
            int node = itr.second;
            int newDis = itr.first;
            pq.erase(pq.begin());
            for (auto it : adj[node]) {
                if (dis[it.first] > dis[node] + it.second) {
                    // someone has already visited the node
                    if (dis[it.first] != 1e9) {
                        pq.erase({dis[it.first], it.first});
                    }
                    dis[it.first] = dis[node] + it.second;
                    pq.insert({dis[node] + it.second, it.first});
                }
            }
        }
        return dis[target];
    }
    int minimumThreshold(int n, vector<vector<int>>& edges, int source,
                         int target, int k) {
        int l = 0, r = 1e9;

        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            vector<vector<pair<int, int>>> adj(n + 1);

            for (int i = 0; i < edges.size(); i++) {
                int u = edges[i][0];
                int v = edges[i][1];
                int wt = edges[i][2];

                if (wt > mid) {
                    wt = 1;
                } else
                    wt = 0;

                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }

            int path = solve(adj, source, target);

            if (path <= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};