class Solution {
public:
    bool solve(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size(), n = grid[0].size();

        if (x + 2 >= m || y + 2 >= n)
            return false;

        set<int> st;

        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                if (grid[i][j] > 9 || grid[i][j] < 1)
                    return false;
                st.insert(grid[i][j]);
            }
        }

        if (st.size() < 9)
            return false;

        int sum = 0;
        for (int i = x; i < x + 3; i++) {
            sum += grid[i][y];
        }

        int r1 = grid[x][y] + grid[x][y + 1] + grid[x][y + 2];
        int r2 = grid[x + 1][y] + grid[x + 1][y + 1] + grid[x + 1][y + 2];
        int r3 = grid[x + 2][y] + grid[x + 2][y + 1] + grid[x + 2][y + 2];

        if (r1 != sum || r2 != sum || r3 != sum)
            return false;

        int c1 = grid[x][y] + grid[x + 1][y] + grid[x + 2][y];
        int c2 = grid[x][y + 1] + grid[x + 1][y + 1] + grid[x + 2][y + 1];
        int c3 = grid[x][y + 2] + grid[x + 1][y + 2] + grid[x + 2][y + 2];

        if (c1 != sum || c2 != sum || c3 != sum)
            return false;

        int d1 = grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2];
        int d2 = grid[x][y + 2] + grid[x + 1][y + 1] + grid[x + 2][y];

        if (d1 != sum || d2 != sum)
            return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m < 3 || n < 3)
            return 0;
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (solve(grid, i, j))
                    cnt++;
            }
        }

        return cnt;
    }
};