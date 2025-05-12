class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> oneRow(rows);
        vector<int> oneCol(cols);
        vector<int> zeroRow(rows);
        vector<int> zeroCol(cols);

        // ROWS KA 0 AND 1 STORE KRO
        for (int i = 0; i < rows; i++) {
            int zero = 0, one = 0;
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    zero++;
                } else if (grid[i][j] == 1) {
                    one++;
                }
            }
            oneRow[i] = one;
            zeroRow[i] = zero;
            zero = 0;
            one = 0;
        }

        // COLS KA 0 AND 1 STORE KRO
        for (int j = 0; j < cols; j++) {
            int zero = 0, one = 0;
            for (int i = 0; i < rows; i++) {
                if (grid[i][j] == 0) {
                    zero++;
                } else if (grid[i][j] == 1) {
                    one++;
                }
            }
            oneCol[j] = one;
            zeroCol[j] = zero;
            one = 0;
            zero = 0;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = oneRow[i] + oneCol[j] - zeroRow[i] - zeroCol[j];
            }
        }
        return grid;
    }
};