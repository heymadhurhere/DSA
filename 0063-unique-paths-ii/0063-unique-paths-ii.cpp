class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<vector<int>>& grid, int m, int n) {
        if (m == 0 && n == 0) {
            return 1;
        }
        if (m < 0 || n < 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];
        int up = 0, left = 0;
        if (m - 1 >= 0 && grid[m - 1][n] == 0) {
            up += solve(dp, grid, m - 1, n);
        }
        if (n - 1 >= 0 && grid[m][n - 1] == 0) {
            left += solve(dp, grid, m, n - 1);
        }
        return dp[m][n] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int m = obstacleGrid.size();
       int n = obstacleGrid[0].size();
       if (obstacleGrid[m - 1][n - 1] == 1) {
        return 0;
       } 
       vector<vector<int>> dp(m, vector<int>(n, -1));
       return solve(dp, obstacleGrid, m - 1, n - 1);
    }
};