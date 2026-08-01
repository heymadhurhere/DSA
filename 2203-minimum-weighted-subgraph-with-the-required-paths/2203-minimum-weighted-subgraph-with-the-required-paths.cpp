using ll = long long;
class Solution {
public:
    void dij(vector<vector<pair<ll, ll>>>& adj, int s, int n, vector<ll>& dis) {
        dis[s] = 0;
        set<pair<ll, ll>> pq;
        pq.insert({dis[s], s});

        while (!pq.empty()) {
            auto pt = *pq.begin();
            ll node = pt.second;
            ll newDis = pt.first;
            pq.erase(pq.begin());
            for (auto it : adj[node]) {
                if (dis[it.first] > dis[node] + it.second) {
                    if (dis[it.first] != LLONG_MAX) {
                        pq.erase({dis[it.first], it.first});
                    }
                    dis[it.first] = dis[node] + it.second;
                    pq.insert({dis[node] + it.second, it.first});
                }
            }
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& e, int s1, int s2,
                            int d) {
        // min(src1->src2->destn, src2->src1->destn, src1->destn + src2->destn)
        vector<vector<pair<ll, ll>>> adj(n), adj2(n);
        for (auto& it : e) {
            ll u = it[0];
            ll v = it[1];
            ll wt = it[2];
            adj[u].push_back({v, wt});
            adj2[v].push_back({u, wt});
        }

        vector<ll> dis1(n, LLONG_MAX), dis2(n, LLONG_MAX);
        dij(adj, s1, n, dis1);
        dij(adj, s2, n, dis2);
        ll ans1 = (dis1[s2] == LLONG_MAX || dis2[d] == LLONG_MAX) ? LLONG_MAX : (dis1[s2] + dis2[d]);
        ll ans2 = (dis2[s1] == LLONG_MAX || dis1[d] == LLONG_MAX) ? LLONG_MAX : (dis2[s1] + dis1[d]);
        if (ans1 != LLONG_MAX && ans2 != LLONG_MAX) {
            return min(ans1, ans2);
        }
        vector<ll> dis3(n, LLONG_MAX);
        dij(adj2, d, n, dis3);
        // calculate dest->everyNode + s1->thatNode + s2->thatNode and keep track of minimum
        ll ans = LLONG_MAX;
        for (ll i = 0; i < n; i++) {
            if (dis1[i] == LLONG_MAX || dis2[i] == LLONG_MAX || dis3[i] == LLONG_MAX) continue;
            ans = min(ans, dis3[i] + dis1[i] + dis2[i]);
        }
        return ans == LLONG_MAX ? -1 : ans;
    }
};