class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        // adjacency list bnao
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        set<pair<long long, long long>> pq;
        // {dis, src}
        pq.insert({0, 0});
        vector<long long> paths(n, 0);
        paths[0] = 1;
        vector<long long> dis(n, 1e18);
        dis[0] = 0;
        while (!pq.empty()) {
            auto it = *pq.begin();
            pq.erase(pq.begin());
            long long wt = it.first;
            int node = it.second;
            if (wt > dis[node])
                continue;
            for (auto itr : adj[node]) {
                int v = itr.first;
                int cost = itr.second;
                if (dis[v] > wt + cost) {
                    dis[v] = wt + cost;
                    paths[v] = paths[node];
                    pq.insert({dis[v], v});
                } else if (dis[v] == wt + cost) {
                    paths[v] = (paths[v] + paths[node]) % mod;
                }
            }
        }
        return (int)paths[n - 1];
    }
};