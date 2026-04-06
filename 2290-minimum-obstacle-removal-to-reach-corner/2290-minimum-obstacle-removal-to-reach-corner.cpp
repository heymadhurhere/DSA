class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 1e7));
        vis[0][0] = 0;

        deque<pair<int, int>> dq; // {row, col};
        dq.push_back({0, 0});

        vector<vector<int>> dirns = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

        while (!dq.empty()) {
            int x = dq.front().first;
            int y = dq.front().second;

            dq.pop_front();

            for (int i = 0; i < 4; i++) {
                int newR = x + dirns[i][0];
                int newC = y + dirns[i][1];

                if (newR >= 0 and newR < m and newC >= 0 and newC < n) {
                    int newCost = vis[x][y] + grid[newR][newC];

                    if (newCost < vis[newR][newC]) {
                        vis[newR][newC] = newCost;

                        if (grid[newR][newC] == 0) {
                            dq.push_front({newR, newC});
                        } else {
                            dq.push_back({newR, newC});
                        }
                    }
                }
            }
        }
        return vis[m - 1][n - 1];
    }
};