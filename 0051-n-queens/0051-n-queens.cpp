class Solution {
public:
    void solve(vector<vector<string>>& ans, int r, int n,
               vector<string>& board) {
        if (r == n) {
            ans.push_back(board);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (isValid(board, r, j, n)) {
                board[r][j] = 'Q';
                solve(ans, r + 1, n, board);
                board[r][j] = '.';
            }
        }
    }
    bool isValid(vector<string>& board, int r, int c, int n) {
        // column check up
        for (int i = 0; i < r; i++) {
            if (board[i][c] == 'Q')
                return false;
        }
        // diagonal checkup
        // 1. upper left
        int i = r - 1, j = c - 1;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        // 2. upper right
        i = r - 1, j = c + 1;
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j++;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s;
        for (int i = 0; i < n; i++) {
            s += '.';
        }
        vector<string> board(n, s);
        solve(ans, 0, n, board);
        return ans;
    }
};