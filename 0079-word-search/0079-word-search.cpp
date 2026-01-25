class Solution {
public:
    bool check(vector<vector<char>>& board, int m, int n, string word, int idx,
               int i, int j, vector<vector<bool>>& vis) {

        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;
        if (vis[i][j])
            return false;

        if (board[i][j] != word[idx])
            return false;
            
        if (idx + 1 == word.length())
            return true;

        // else if (board[i][j] == word[idx])
        //     idx++;
        vis[i][j] = true;
        bool ans = check(board, m, n, word, idx + 1, i + 1, j, vis) ||
                   check(board, m, n, word, idx + 1, i - 1, j, vis) ||
                   check(board, m, n, word, idx + 1, i, j + 1, vis) ||
                   check(board, m, n, word, idx + 1, i, j - 1, vis);
        vis[i][j] = false;

        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (check(board, m, n, word, 0, i, j, vis))
                    return true;
            }
        }
        return false;
    }
};