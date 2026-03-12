class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // first and last row
        for (int col = 0; col < n; col++) {
            // first row
            if (board[0][col] == 'O') {
                q.push({0, col});
                vis[0][col] = true;
                board[0][col] = 'Z';
            }
            // last row
            if (board[m - 1][col] == 'O') {
                q.push({m - 1, col});
                vis[m - 1][col] = true;
                board[m - 1][col] = 'Z';
            }
        }

        // first and last col
        for (int row = 1; row < m - 1; row++) {
            // first col
            if (board[row][0] == 'O') {
                q.push({row, 0});
                vis[row][0] = true;
                board[row][0] = 'Z';
            }
            // last col
            if (board[row][n - 1] == 'O') {
                q.push({row, n - 1});
                vis[row][n - 1] = true;
                board[row][n - 1] = 'Z';
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 and newX < m and newY >= 0 and newY < n and
                    !vis[newX][newY] and board[newX][newY] == 'O') {
                    vis[newX][newY] = true;
                    q.push({newX, newY});
                    board[newX][newY] = 'Z';
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'Z') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};