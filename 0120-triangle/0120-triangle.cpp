class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<vector<int>>& triangle, int r,
              int c) {
        if (r == triangle.size() - 1) {
            return triangle[r][c]; // we have to check on every element of the
                                   // row and not just the last element
        }

        if (dp[r][c] != -1)
            return dp[r][c];
        int down = INT_MAX, downRight = INT_MAX;
        if (r + 1 < triangle.size()) {
            down = solve(dp, triangle, r + 1, c);
        }
        if (r + 1 < triangle.size() && c + 1 < triangle[r + 1].size()) {
            downRight = solve(dp, triangle, r + 1, c + 1);
        }
        return dp[r][c] = triangle[r][c] + min(down, downRight);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        for (int i = 0; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[i][j] = -1;
            }
        }
        return solve(dp, triangle, 0, 0);
    }
};