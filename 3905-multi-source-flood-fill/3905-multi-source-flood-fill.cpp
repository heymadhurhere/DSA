class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<pair<int, int>>> mat(
            n, vector<pair<int, int>>(m, {0, 0})); // pair -> {color, time}
        queue<pair<int, pair<int, int>>> q;        // {x, {y, time}};

        vector<vector<int>> srcs(n, vector<int>(m, 0));

        int sz = sources.size();
        for (int i = 0; i < sz; i++) {
            int x = sources[i][0];
            int y = sources[i][1];
            int color = sources[i][2];

            mat[x][y].first = max(mat[x][y].first, color);
            mat[x][y].second = 0;
            vis[x][y] = true;
            q.push({x, {y, 0}});
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {-1, 0, 1, 0};

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second.first;
            int time = q.front().second.second;
            int currCol = mat[x][y].first;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 and nx < n and ny >= 0 and ny < m) {
                    // 2 cases
                    // if not vis
                    if (!vis[nx][ny]) {
                        mat[nx][ny] = {currCol, time + 1};
                        vis[nx][ny] = true;
                        q.push({nx, {ny, time + 1}});
                    }
                    // if already vis
                    else {
                        if (mat[nx][ny].second == time + 1) {
                            if (currCol > mat[nx][ny].first) {
                                mat[nx][ny].first = currCol;
                            }
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = mat[i][j].first;
            }
        }
        return ans;
    }
};