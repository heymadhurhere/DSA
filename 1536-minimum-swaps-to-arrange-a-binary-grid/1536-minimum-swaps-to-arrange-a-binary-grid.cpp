class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int col = 0; col < n; col++) {
            int cnt = 0;
            for (int row = 0; row < n; row++) {
                if (grid[row][col] == 0) cnt++;
            }
            if (cnt < col) return -1;
        }

        vector<int> zeroEnd(n, n);
        for (int r = 0; r < n; r++) {
            for (int c = n - 1; c >= 0; c--) {
                if (grid[r][c] == 1) {
                    zeroEnd[r] = n - c - 1;
                    break;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int rq = n - i - 1;
            int j = i;
            while (j < n && zeroEnd[j] < rq) {
                j++;
            }
            if (j == n) {
                return -1;
            }
            ans += j - i;
            while (j > i) {
                swap(zeroEnd[j], zeroEnd[j - 1]);
                j--;
            }
        }
        return ans;
    }
};