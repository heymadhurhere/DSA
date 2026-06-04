class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>>& mat,
            vector<vector<int>>& dp) {
        if (dp[i][j] != 0) {
            return dp[i][j];
        }

        int maxi = 1;

        for (int r = 0; r < m; r++) {
            if (mat[r][j] > mat[i][j]) {
                maxi = max(maxi, 1 + dfs(r, j, m, n, mat, dp));
            }
        }

        for (int c = 0; c < n; c++) {
            if (mat[i][c] > mat[i][j]) {
                maxi = max(maxi, 1 + dfs(i, c, m, n, mat, dp));
            }
        }
        return dp[i][j] = maxi;
    }
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // for 1D matrix -> NICE OBSERVATION
        // !!**remember for edge cases**!!
        if (m == 1) {
            unordered_set<int> ans(mat[0].begin(), mat[0].end());
            return ans.size();
        }

        if (n == 1) {
            unordered_set<int> ans;
            for (int i = 0; i < m; ++i) {
                ans.insert(mat[i][0]);
            }
            return ans.size();
        }

        // cout << m << " " << n << "\n";
        // cout << 1LL * m * n * (m + n);
        // return m;

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j, m, n, mat, dp));
            }
        }

        cout << ans;

        return ans;
    }
};