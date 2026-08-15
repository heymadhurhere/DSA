class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjR, vector<vector<int>>& adjB,
             int last, int step, vector<vector<int>>& dist) {
        if (step >= dist[node][last])
            return;

        dist[node][last] = step;

        if (last == 0) { // red
            for (auto& it : adjB[node]) {
                dfs(it, adjR, adjB, 1, step + 1, dist);
            }
        } else { // blue
            for (auto& it : adjR[node]) {
                dfs(it, adjR, adjB, 0, step + 1, dist);
            }
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r,
                                         vector<vector<int>>& b) {
        vector<vector<int>> adjR(n), adjB(n);
        for (auto it : r) {
            int u = it[0];
            int v = it[1];
            adjR[u].push_back(v);
        }
        for (auto it : b) {
            int u = it[0];
            int v = it[1];
            adjB[u].push_back(v);
        }

        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));

        for (auto& it : adjR[0]) {
            dfs(it, adjR, adjB, 0, 1, dist);
        }

        for (auto& it : adjB[0]) {
            dfs(it, adjR, adjB, 1, 1, dist);
        }

        dist[0][0] = 0;
        dist[0][1] = 0;

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int tmp = min(dist[i][0], dist[i][1]);
            if (tmp == INT_MAX) {
                ans[i] = -1;
            } else {
                ans[i] = tmp;
            }
        }
        return ans;
    }
};