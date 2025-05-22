class Solution {
public:
    int solve(int i, int j1, int j2, int r, int c,
              vector<vector<vector<int>>>& dp, vector<vector<int>>& grid) {
        if (j1 >= c || j1 < 0 || j2 >= c || j2 < 0) {
            return INT_MIN;
        }
        if (i == r - 1) {
            if (j1 == j2) {
                return grid[i][j1];
            } else {
                return grid[i][j1] + grid[i][j2];
            }
        }

        if (dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }
        long long ans = LLONG_MIN;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int newj1 = j1 + dj1;
                int newj2 = j2 + dj2;
                int next = solve(i + 1, newj1, newj2, r, c, dp, grid);
                if (next != INT_MIN) {
                    long long cherries = 0;
                    if (j1 == j2) {
                        cherries = grid[i][j1];
                    } else {
                        cherries = grid[i][j1] + grid[i][j2];
                    }
                    cherries += next;
                    ans = max(ans, cherries);
                }
            }
        }
        return dp[i][j1][j2] = (int)ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(
            r, vector<vector<int>>(c, vector<int>(c, -1)));
        int ans = solve(0, 0, c - 1, r, c, dp, grid);
        return ans;
    }
};