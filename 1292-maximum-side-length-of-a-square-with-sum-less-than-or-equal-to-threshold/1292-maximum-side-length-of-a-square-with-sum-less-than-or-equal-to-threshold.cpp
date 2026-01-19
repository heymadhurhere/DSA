class Solution {
public:
    bool isValid(vector<vector<int>>& mat, int threshold, int i, int j, int k) {
        int sum = 0;

        // total sum
        for (int x = i; x < i + k; x++) {
            for (int y = j; y < j + k; y++) {
                sum += mat[x][y];
                if (sum > threshold)
                    return false;
            }
        }
        return true;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;

        // iterate over all possible squares
        int low = 1, high = min(m, n);
        while (low <= high) {
            int k = low + (high - low) / 2;
            bool flag = false;
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    if (isValid(mat, threshold, i, j, k)) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) {
                ans = k;
                low = k + 1;
            } else {
                high = k - 1;
            }
        }
        return ans;
    }
};