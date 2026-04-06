class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> dirns = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        deque<pair<int, pair<int, int>>> dq; //{row, {col, cost}}

        dq.push_back({0, {0, 0}});

        while (!dq.empty()) {
            int r = dq.front().first;
            int c = dq.front().second.first;
            int cost = dq.front().second.second;
            dq.pop_front();

            if (r == m - 1 and c == n - 1) {
                return cost;
            }

            if (vis[r][c])
                continue;

            vis[r][c] = true;

            for (int i = 1; i <= 4; i++) {
                int newR = r + dirns[i][0];
                int newC = c + dirns[i][1];

                if (newR >= 0 and newR < m and newC >= 0 and newC < n and
                    !vis[newR][newC]) {
                    if (grid[r][c] == i) {
                        dq.push_front({newR, {newC, cost}});
                    } else {
                        dq.push_back({newR, {newC, cost + 1}});
                    }
                }
            }
        }
        return -1;
    }
};