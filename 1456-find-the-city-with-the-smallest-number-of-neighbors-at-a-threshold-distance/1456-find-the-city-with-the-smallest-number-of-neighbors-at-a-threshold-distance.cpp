class Solution {
public:
    int findMin(vector<int>& store) {
        int ans = store[0];
        for (int i = 0; i < store.size(); i++) {
            ans = min(ans, store[i]);
        }
        return ans;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // create 2d matrix for distance
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] == 1e9 || dist[via][j] == 1e9)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
        vector<int> store(n);
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold && i != j) {
                    cnt++;
                }
                store[i] = cnt;
            }
        }
        int city = findMin(store);
        for (int i = n - 1; i >= 0; i--) {
            if (store[i] == city) {
                return i;
            }
        }
        return 0;
    }
};