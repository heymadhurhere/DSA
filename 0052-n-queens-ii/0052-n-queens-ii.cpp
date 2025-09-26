class Solution {
public:
    void solve(vector<string>& board, int r, int& cnt, int n) {
        if (r == n) {
            cnt++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(board, r, i, n)) {
                board[r][i] = 'Q';
                solve(board, r + 1, cnt, n);
                board[r][i] = '.';
            }
        }
    }
    bool isValid(vector<string>& board, int r, int c, int n) {
        // column check up
        for (int i = 0; i < r; i++) {
            if (board[i][c] == 'Q') return false;
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
    int totalNQueens(int n) {
        int cnt = 0;
        string s;
        for (int i = 0; i < n; i++) {
            s += '.';
        }
        vector<string> board(n, s);
        solve(board, 0, cnt, n);
        return cnt;
    }
};