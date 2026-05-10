#define ll long long
class Solution {
public:
    vector<ll> solve(vector<vector<pair<ll, ll>>>& adj, ll source) {
        vector<ll> dis(adj.size(), 1e9);
        dis[source] = 0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
                       greater<pair<ll, ll>>>
            pq;
        pq.push({0, source});
        while (!pq.empty()) {
            auto itr = pq.top();
            pq.pop();
            ll node = itr.second;
            ll newDis = itr.first;

            if (newDis > dis[node])
                continue;

            for (auto it : adj[node]) {
                if (dis[it.first] > dis[node] + it.second) {
                    dis[it.first] = dis[node] + it.second;
                    pq.push({dis[it.first], it.first});
                }
            }
        }
        return dis;
    }
    vector<int> minCost(int n, vector<int>& prices,
                        vector<vector<int>>& roads) {
        vector<vector<pair<ll, ll>>> adj_empty(n);

        for (auto& it : roads) {
            ll u = it[0];
            ll v = it[1];
            ll cost = it[2];

            adj_empty[u].push_back({v, cost});
            adj_empty[v].push_back({u, cost});
        }

        vector<vector<ll>> djkistra_empty(n);

        for (ll i = 0; i < n; i++) {
            djkistra_empty[i] = solve(adj_empty, i);
        }

        vector<vector<pair<ll, ll>>> adj_taxed(n);

        for (auto& it : roads) {
            ll u = it[0];
            ll v = it[1];
            ll cost = it[2];
            ll tax = it[3];

            long long wt = cost * tax;

            adj_taxed[u].push_back({v, wt});
            adj_taxed[v].push_back({u, wt});
        }

        vector<vector<ll>> djkistra_taxed(n);

        for (ll i = 0; i < n; i++) {
            djkistra_taxed[i] = solve(adj_taxed, i);
        }

        vector<int> ans;
        for (ll i = 0; i < n; i++) {
            ll local = prices[i];

            long long travel = INT_MAX;
            for (ll j = 0; j < n; j++) {
                ll go_price = djkistra_empty[i][j];
                ll come_price = djkistra_taxed[j][i];
                ll apple_price = prices[j];

                if (go_price != 1e9 && come_price != 1e9) {
                    long long total = 1LL * go_price + come_price + apple_price;
                    travel = min(travel, total);
                }
            }
            ll final_price = min((long long)local, travel);
            ans.push_back(final_price);
        }
        return ans;
    }
};