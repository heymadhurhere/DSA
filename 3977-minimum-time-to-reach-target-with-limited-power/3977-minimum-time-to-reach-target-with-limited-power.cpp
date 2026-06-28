using ll = long long;
class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int p,
                                      vector<int>& cost, int src, int tgt) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }

        vector<vector<ll>> dis(n, vector<ll>(p + 1, LLONG_MAX));
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>>
            pq; // {time, node, remining power}

        dis[src][p] = 0;
        pq.push({0, src, p});
        ll ans = -1, pow = -1;

        while (!pq.empty()) {
            ll time = pq.top()[0], u = pq.top()[1], remP = pq.top()[2];
            pq.pop();
            if (time != dis[u][remP])
                continue;
            if (ans != -1 && time > ans)
                break;
            if (u == tgt) {
                if (ans == -1)
                    ans = time;
                pow = max(remP, pow);
                continue;
            }

            if (remP < cost[u])
                continue;
            ll nxtP = remP - cost[u];
            for (auto& it : adj[u]) {
                ll v = it.first;
                ll w = it.second;
                if (time + w < dis[v][nxtP]) {
                    dis[v][nxtP] = time + w;
                    pq.push({time + w, v, nxtP});
                }
            }
        }
        return {ans, pow};
    }
};