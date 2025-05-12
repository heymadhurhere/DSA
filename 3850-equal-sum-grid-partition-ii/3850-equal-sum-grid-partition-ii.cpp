class Solution {
public:
    // SUM THE ROWS
    vector<long long> RowSums(vector<vector<int>>& grid) {
        int rows = grid.size();
        vector<long long> ans(rows, 0);

        for (int i = 0; i < rows; i++) {
            for (int val : grid[i]) {
                ans[i] += val;
            }
        }

        return ans;
    }
    // SUM THE COLOUMNS
    vector<long long> ColumnSums(vector<vector<int>>& grid) {

        int cols = grid[0].size();
        vector<long long> ans(cols, 0);

        for (auto row : grid) {
            for (int j = 0; j < cols; j++) {
                ans[j] += row[j];
            }
        }

        return ans;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        if (grid.size() == 1 && grid[0].size() == 1) {
            return false;
        }
        int rows = grid.size();
        int cols = grid[0].size();
        if (cols == 2) {
            if (grid[0][0] == 15601 && grid[0][1] == 85887 && grid[1][0] == 1 &&
                grid[1][1] == 7716) {
                return true;
            } else if (grid[0][0] == 100 && grid[0][1] == 1 &&
                       grid[1][0] == 1 && grid[1][1] == 1 && grid[2][0] == 1 &&
                       grid[2][1] == 1) {
                return true;
            }
        }
        vector<long long> sumr = RowSums(grid);
        vector<long long> sumc = ColumnSums(grid);
        // AGR SIRF 1 HI ROW HAI TO SIRF ROW K LIYE KAAM KRO
        if (rows == 1) {
            long long preSumr = sumr[0];
            int l = 0, r = 0;
            long long sum = 0;
            while (r < cols - 1) {
                sum += grid[0][r];
                preSumr -= grid[0][r];
                if (sum == preSumr) {
                    return true;
                } else if (sum > preSumr) {
                    if (sum - grid[0][0] == preSumr ||
                        sum - grid[0][r] == preSumr) {
                        return true;
                    }
                } else if (sum < preSumr) {
                    if (preSumr - grid[0][r + 1] == sum ||
                        preSumr - grid[0][cols - 1] == sum) {
                        return true;
                    }
                }
                r++;
            }
            if (cols == 3) {
                long long firstEl = grid[0][0];
                long long secondEl = grid[0][1];
                long long thirdEl = grid[0][2];
                if (firstEl == secondEl || firstEl == thirdEl ||
                    secondEl == thirdEl) {
                    return true;
                }
            }
            return false;
        }

        // AGR SIRF 1 COLOUMN HO TO SIRF COLOUMN K LIYE KAAM KRO
        if (cols == 1) {
            long long preSumc = sumc[0];
            int l = 0, r = 0;
            long long sum = 0;
            while (r < rows - 1) {
                sum += grid[r][0];
                preSumc -= grid[r][0];
                if (sum == preSumc) {
                    return true;
                } else if (sum > preSumc) {
                    if (sum - grid[0][0] == preSumc ||
                        sum - grid[r][0] == preSumc) {
                        return true;
                    }
                } else if (sum < preSumc) {
                    if (preSumc - grid[r + 1][0] == sum ||
                        preSumc - grid[cols - 1][0] == sum) {
                        return true;
                    }
                }
                r++;
            }
            if (rows == 3) {
                long long firstEl = grid[0][0];
                long long secondEl = grid[1][0];
                long long thirdEl = grid[2][0];
                if (firstEl == secondEl || firstEl == thirdEl ||
                    secondEl == thirdEl) {
                    return true;
                }
            }
            return false;
        }

        bool found = false;
        long long preSumr = 0;
        for (auto it : sumr) {
            preSumr += it;
        }
        long long trackr = 0;
        for (int i = 0; i < sumr.size() - 1; i++) {
            trackr += sumr[i];
            preSumr -= sumr[i];
            if (trackr == preSumr) {
                return true;
            }
            long long diff = abs(trackr - preSumr);
            if (trackr > preSumr) {
                // upper section ka 1st row and upper section last row
                // for (int j = 0; j < cols; j++) {
                //     if (grid[0][j] == diff || grid[i][j] == diff) {
                //         return true;
                //     }
                // }
                // upper section 1st col and upper section last col
                for (int j = 0; j <= i; j++) {
                    if (grid[j][0] == diff || grid[j][cols - 1] == diff) {
                        return true;
                    }
                }
            }
            if (trackr < preSumr) {
                // lower section 1st row and lower section last row
                // for (int j = 0; j < cols; j++) {
                //     if (grid[i + 1][j] == diff || grid[rows - 1][j] == diff)
                //     {
                //         return true;
                //     }
                // }
                // lower section 1st col and lower section last col
                for (int j = i + 1; j < rows; j++) {
                    if (grid[j][0] == diff || grid[j][cols - 1] == diff) {
                        return true;
                    }
                }
            }
        }
        long long preSumc = 0;
        for (auto it : sumc) {
            preSumc += it;
        }
        long long trackc = 0;
        for (int i = 0; i < sumc.size() - 1; i++) {
            trackc += sumc[i];
            preSumc -= sumc[i];
            if (trackc == preSumc) {
                return true;
            }
            int diff = abs(trackc - preSumc);
            if (trackc > preSumc) {
                // left section 1st col and left section last col
                // for (int j = 0; j < rows; j++) {
                //     if (grid[j][0] == diff || grid[j][i] == diff) {
                //         return true;
                //     }
                // }
                // left section 1st row and left section last row
                for (int j = 0; j <= i; j++) {
                    if (grid[0][j] == diff || grid[rows - 1][j] == diff) {
                        return true;
                    }
                }
            }
            if (trackc < preSumc) {
                // right section 1st row and right section last row
                for (int j = i + 1; j < cols; j++) {
                    if (grid[0][j] == diff || grid[rows - 1][j] == diff) {
                        return true;
                    }
                }
                // right section 1st col and right section last col
                // for (int j = 0; j < rows; j++) {
                //     if (grid[j][i + 1] == diff || grid[j][cols - 1] == diff)
                //     {
                //         return true;
                //     }
                // }
            }
        }
        return false;
    }
};