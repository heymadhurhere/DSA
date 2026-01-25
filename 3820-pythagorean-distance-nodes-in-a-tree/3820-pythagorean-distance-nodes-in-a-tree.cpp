class Solution {
public:
    vector<int> dist(int n, vector<vector<int>>& adj, int src) {
        vector<int> ans(n, -1);
        queue<int> q;

        ans[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (ans[v] == -1) {
                    ans[v] = ans[u] + 1;
                    q.push(v);
                }
            }
        }

        return ans;
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> distx = dist(n, adj, x);
        vector<int> disty = dist(n, adj, y);
        vector<int> distz = dist(n, adj, z);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            tmp.push_back(distx[i]);
            tmp.push_back(disty[i]);
            tmp.push_back(distz[i]);

            sort(tmp.begin(), tmp.end());

            long long num1 = tmp[0];
            long long num2 = tmp[1];
            long long num3 = tmp[2];

            if (num1 * num1 + num2 * num2 == num3 * num3)
                cnt++;
        }
        return cnt;
    }
};