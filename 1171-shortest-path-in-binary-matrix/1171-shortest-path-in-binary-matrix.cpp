class Solution {
public:
    // ye code bbhi sahi chalna chaiye tha
    // pata hi kyu nahi chala h
    // void dfs(vector<vector<int>>& edges, vector<vector<bool>>& vis,
    //          vector<vector<int>>& grid, int n, int x, int y) {
    //     vis[x][y] = true;
    //     for (int i = -1; i <= 1; i++) {
    //         for (int j = -1; j <= 1; j++) {
    //             if (i == 0 && j == 0)
    //                 continue;
    //             int newX = x + i;
    //             int newY = y + j;
    //             if (newX >= 0 && newY >= 0 && newX < n && newY < n &&
    //                 !vis[newX][newY] && grid[newX][newY] == 0) {
    //                 edges.push_back({x, y, newX, newY});
    //                 dfs(edges, vis, grid, n, newX, newY);
    //             }
    //         }
    //     }
    // }
    // int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    //     // step 1: make graph
    //     vector<vector<int>> edges;
    //     int n = grid.size();
    //     if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
    //         return -1;
    //     }
    //     vector<vector<bool>> vis(n, vector<bool>(n, false));
    //     dfs(edges, vis, grid, n, 0, 0);
    //     if (!vis[n - 1][n - 1]) {
    //         return -1;
    //     }

    //     // step 2: make adj list
    //     vector<vector<vector<vector<int>>>> adj(n,
    //     vector<vector<vector<int>>>(n)); for (auto it: edges) {
    //         int ux = it[0];
    //         int uy = it[1];
    //         int vx = it[2];
    //         int vy = it[3];
    //         adj[ux][uy].push_back({vx, vy});
    //         adj[vx][vy].push_back({ux, uy});
    //     }

    //     vector<vector<int>> dist(n, vector<int>(n, 1e9));
    //     dist[0][0] = 1;

    //     queue<pair<int, int>> q;
    //     q.push({0, 0});
    //     while (!q.empty()) {
    //         auto node = q.front();
    //         q.pop();
    //         int ux = node.first;
    //         int uy = node.second;
    //         for (auto it : adj[ux][uy]) {
    //             int vx = it[0];
    //             int vy = it[1];
    //             if (dist[ux][uy] + 1 < dist[vx][vy]) {
    //                 dist[vx][vy] = dist[ux][uy] + 1;
    //                 q.push({vx, vy});
    //             }
    //         }
    //     }
    //     if (dist[n - 1][n - 1] == 1e9) {
    //         return -1;
    //     }
    //     return dist[n - 1][n - 1];
    // }
    /*FRESH START*/
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 1;

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int ux = node.first;
            int uy = node.second;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    int vx = ux + i;
                    int vy = uy + j;
                    // check boundary condition
                    if (vx >= 0 && vy >= 0 && vx < n && vy < n &&
                        grid[vx][vy] == 0) {
                        if (dist[vx][vy] > dist[ux][uy] + 1) {
                            dist[vx][vy] = dist[ux][uy] + 1;
                            q.push({vx, vy});
                        }
                    }
                }
            }
        }
        if (dist[n - 1][n - 1] == 1e9) {
            return -1;
        }
        return dist[n - 1][n - 1];
    }
};