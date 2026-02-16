class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int cnt = 1;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int sRow = 0, sCol = 0, eRow = n - 1, eCol = n - 1;
        while (cnt <= n * n) {
            // start row
            for (int i = sCol; i <= eCol; i++) {
                ans[sRow][i] = cnt++;
            }
            sRow++;
            // end col
            for (int j = sRow; j <= eRow; j++) {
                ans[j][eCol] = cnt++;
            }
            eCol--;
            // end row
            for (int i = eCol; i >= sCol; i--) {
                ans[eRow][i] = cnt++;
            }
            eRow--;
            // start col
            for (int j = eRow; j >= sRow; j--) {
                ans[j][sCol] = cnt++;
            }
            sCol++;
        }
        return ans;
    }
};