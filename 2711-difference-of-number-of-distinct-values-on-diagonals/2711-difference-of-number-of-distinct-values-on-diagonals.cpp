class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                unordered_map<int, int> mppL;
                unordered_map<int, int> mppR;

                int r = i - 1, c = j - 1;
                while (r >= 0 and c >= 0) {
                    mppL[grid[r][c]]++;
                    r--;
                    c--;
                }
                r = i + 1, c = j + 1;
                while (r < m and c < n) {
                    mppR[grid[r][c]]++;
                    r++;
                    c++;
                }
                int to_insert = abs((int)mppL.size() - (int)mppR.size());
                ans[i][j] = to_insert;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        return ans;
    }
};