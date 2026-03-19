class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> tmp(
            m, vector<vector<int>>(n, vector<int>(3, 0)));
        // 0 -> X, 1 -> Y and 2 -> .

        if (grid[0][0] == 'X') {
            tmp[0][0][0]++;
        } else if (grid[0][0] == 'Y') {
            tmp[0][0][1]++;
        } else {
            tmp[0][0][2]++;
        }

        // first row
        for (int i = 1; i < n; i++) {
            tmp[0][i] = tmp[0][i - 1];
            if (grid[0][i] == 'X') {
                tmp[0][i][0]++;
            } else if (grid[0][i] == 'Y') {
                tmp[0][i][1]++;
            } else {
                tmp[0][i][2]++;
            }
        }

        // first col
        for (int i = 1; i < m; i++) {
            tmp[i][0] = tmp[i - 1][0];
            if (grid[i][0] == 'X') {
                tmp[i][0][0]++;
            } else if (grid[i][0] == 'Y') {
                tmp[i][0][1]++;
            } else {
                tmp[i][0][2]++;
            }
        }

        // all other cells except first row and first col
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    tmp[i][j][k] = tmp[i - 1][j][k] + tmp[i][j - 1][k] -
                                   tmp[i - 1][j - 1][k];
                }

                if (grid[i][j] == 'X')
                    tmp[i][j][0]++;
                else if (grid[i][j] == 'Y')
                    tmp[i][j][1]++;
                else
                    tmp[i][j][2]++;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (tmp[i][j][0] == tmp[i][j][1] and tmp[i][j][0] > 0)
                    ans++;
            }
        }

        return ans;
    }
};