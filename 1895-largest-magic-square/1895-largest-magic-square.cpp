class Solution {
public:
    bool check(vector<vector<int>>& grid, int i, int j, int k) {
        int sum = 0;
        // row sum
        for (int x = i; x < i + k; x++) {
            int s = 0;
            for (int y = j; y < j + k; y++) {
                s += grid[x][y];
            }
            if (x == i)
                sum = s;
            else if (sum != s)
                return false;
        }

        // col sum;
        for (int y = j; y < j + k; y++) {
            int s = 0;
            for (int x = i; x < i + k; x++) {
                s += grid[x][y];
            }
            if (sum != s)
                return false;
        }

        // diagonal sum
        int s = 0;
        for (int d = 0; d < k; d++) {
            s += grid[i + d][j + d];
        }
        if (sum != s)
            return false;

        s = 0;
        for (int d = 0; d < k; d++) {
            s += grid[i + d][j + k - d - 1];
        }
        if (sum != s)
            return false;
        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 1;

        for (int sq_sz = 2; sq_sz <= min(m, n); sq_sz++) {
            for (int i = 0; i + sq_sz <= m; i++) {
                for (int j = 0; j + sq_sz <= n; j++) {
                    if (check(grid, i, j, sq_sz))
                        ans = sq_sz;
                }
            }
        }
        return ans;
    }
};