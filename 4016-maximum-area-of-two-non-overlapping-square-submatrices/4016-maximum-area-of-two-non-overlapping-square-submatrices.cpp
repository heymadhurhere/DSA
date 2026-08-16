class Solution {
public:
    bool check(int k, vector<vector<int>>& dp) {
        int m = dp.size() - 1, n = dp[0].size() - 1;
        int rMin = m, cMin = n, rMax = -1, cMax = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] >= k) {
                    rMin = min(rMin, i);
                    rMax = max(rMax, i);
                    cMin = min(cMin, j);
                    cMax = max(cMax, j);
                }
            }
        }
        if (rMin != m and rMax != -1 and rMax - rMin >= k)
            return true;
        if (cMin != n and cMax != -1 and cMax - cMin >= k)
            return true;
        return false;
    }
    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (mat[i][j] == 1) {
                    dp[i][j] =
                        1 + min({dp[i][j + 1], dp[i + 1][j], dp[i + 1][j + 1]});
                }
            }
        }

        int ans = 0, l = 1, h = min(m, n);
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (check(mid, dp)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans * ans;
    }
};