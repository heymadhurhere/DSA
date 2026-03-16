class Solution {
public:
    int count(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0)
                    continue;

                int level = 1;

                while (true) {

                    int r = i + level;
                    int left = j - level;
                    int right = j + level;

                    if (r >= m || left < 0 || right >= n)
                        break;

                    bool ok = true;

                    for (int c = left; c <= right; c++) {
                        if (grid[r][c] == 0) {
                            ok = false;
                            break;
                        }
                    }

                    if (!ok)
                        break;

                    cnt++;
                    level++;
                }
            }
        }

        return cnt;
    }
    int countPyramids(vector<vector<int>>& grid) {
        int ans = count(grid);

        reverse(grid.begin(), grid.end());

        ans += count(grid);

        return ans;
    }
};