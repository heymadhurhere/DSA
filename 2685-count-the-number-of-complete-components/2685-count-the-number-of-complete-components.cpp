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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        DisjointSet ds(n);
        for (auto& it : edges) {
            ds.unionBySize(it[0], it[1]);
        }

        unordered_map<int, vector<int>> comps;

        for (int i = 0; i < n; i++) {
            int par = ds.findUPar(i);
            comps[par].push_back(i);
        }

        int cnt = 0;

        for (auto it : comps) {
            int comp_sz = it.second.size();
            bool flag = true;

            for (auto node : it.second) {
                if (adj[node].size() != comp_sz - 1) {
                    flag = false;
                    break;
                }
            }

            if (flag)
                cnt++;
        }
        return cnt;
    }
};