class Solution {
public:
    int solve(vector<vector<int>>& fruits, int n, int moves, int i, int j,
              vector<vector<int>>& dp) {
        if (i < 0 || i >= n || j >= n) {
            return INT_MIN;
        }
        if (i == n - 1 && j == n - 1 && moves == n - 1) {
            return fruits[i][j];
        }
        if (moves >= n)
            return INT_MIN;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ru = solve(fruits, n, moves + 1, i - 1, j + 1, dp);
        int r = solve(fruits, n, moves + 1, i, j + 1, dp);
        int dr = solve(fruits, n, moves + 1, i + 1, j + 1, dp);
        return dp[i][j] = fruits[i][j] + max({ru, r, dr});
    }
    int solve2(vector<vector<int>>& fruits, int n, int moves, int i, int j,
               vector<vector<int>>& dp2) {
        if (i >= n || j >= n || j < 0) {
            return INT_MIN;
        }
        if (i == n - 1 && j == n - 1 && moves == n - 1) {
            return fruits[i][j];
        }

        if (moves >= n)
            return INT_MIN;
        if (dp2[i][j] != -1)
            return dp2[i][j];
        int ld = solve2(fruits, n, moves + 1, i + 1, j - 1, dp2);
        int d = solve2(fruits, n, moves + 1, i + 1, j, dp2);
        int dr = solve2(fruits, n, moves + 1, i + 1, j + 1, dp2);
        return dp2[i][j] = fruits[i][j] + max({ld, d, dr});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int sum = 0;
        int n = fruits.size();
        for (int i = 0; i < n; i++) {
            sum += fruits[i][i];
            fruits[i][i] = 0;
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        int tr = solve2(fruits, n, 0, 0, n - 1, dp2);
        int bl = solve(fruits, n, 0, n - 1, 0, dp);
        return sum + tr + bl - fruits[n - 1][n - 1];
    }
};