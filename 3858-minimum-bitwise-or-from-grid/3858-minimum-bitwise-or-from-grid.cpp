class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int ans = (1 << 20) - 1;

        for (int bit = 19; bit >= 0; bit--) {
            int wans = ans ^ (1 << bit);
            bool possible = true;
            for (int i = 0; i < r; i++) {
                bool sub = false;
                for (int j = 0; j < c; j++) {
                    if ((wans | grid[i][j]) == wans)
                        sub = true;
                }
                if (!sub)
                    possible = false;
            }
            if (!possible)
                continue;
            ans = wans;
        }
        return ans;
    }
};