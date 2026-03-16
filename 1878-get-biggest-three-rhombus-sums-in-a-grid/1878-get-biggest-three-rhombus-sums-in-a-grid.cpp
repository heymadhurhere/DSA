class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int lim = (min(m, n) + (min(m, n) % 2 != 0)) / 2;
        set<int> st;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                st.insert(grid[i][j]);

                for (int k = 1; k < lim; k++) {
                    if (i + 2 * k >= m || j - k < 0 || j + k >= n)
                        break;

                    int sum = 0;

                    // top to right
                    for (int x = 0; x < k; x++) {
                        sum += grid[i + x][j + x];
                    }
                    // right to down
                    for (int x = 0; x < k; x++) {
                        sum += grid[i + k + x][j + k - x];
                    }
                    // down to left
                    for (int x = 0; x < k; x++) {
                        sum += grid[i + 2 * k - x][j - x];
                    }
                    // left to top
                    for (int x = 0; x < k; x++) {
                        sum += grid[i + k - x][j - k + x];
                    }

                    st.insert(sum);
                }
            }
        }
        vector<int> ans(st.rbegin(), st.rend());
        if (ans.size() < 3)
            return ans;
        return {ans[0], ans[1], ans[2]};
    }
};