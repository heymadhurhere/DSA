class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (matrix[r][c] == 1 && r > 0) {
                    matrix[r][c] += matrix[r - 1][c];
                }
            }

            vector<int> tmp = matrix[r];
            sort(tmp.rbegin(), tmp.rend());

            for (int i = 0; i < n; i++) {
                int b = i + 1;
                int h = tmp[i];

                ans = max(ans, b * h);
            }
        }
        return ans;
    }
};