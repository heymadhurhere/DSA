class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // path compression
    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        // both ranks are equal
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int dfs(int node, vector<vector<pair<int, int>>>& adj, vector<bool>& vis) {
        int ans = -1;
        vis[node] = true;

        for (auto& it : adj[node]) {
            int v = it.first;
            int wt = it.second;

            ans = ans & wt;
            if (!vis[v]) {
                ans = ans & dfs(v, adj, vis);
            }
        }
        return ans;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        // find the ultimate parents of all nodes
        // do dfs from all nodes and calculate the and(&) of all the weights in
        // that component store the and result in a map which stores the and of
        // the component according to the ultimate parent
        DisjointSet ds(n);
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        for (auto& it : edges) {
            ds.unionBySize(it[0], it[1]);
        }

        vector<int> par(n);

        for (int i = 0; i < n; i++) {
            int p = ds.findUPar(i);
            par[i] = p;
        }
        unordered_set<int> st(par.begin(), par.end());
        unordered_map<int, int> mpp;
        vector<bool> vis(n, false);
        for (auto& it : st) {
            int num = it;
            int ans = dfs(it, adj, vis);
            mpp[it] = ans;
        }

        vector<int> ans;

        for (auto& it : query) {
            int s = it[0];
            int t = it[1];

            if (ds.findUPar(s) != ds.findUPar(t)) {
                ans.push_back(-1);
            } else {
                int p = ds.findUPar(s);
                int cost = mpp[p];
                ans.push_back(cost);
            }
        }
        return ans;
    }
};