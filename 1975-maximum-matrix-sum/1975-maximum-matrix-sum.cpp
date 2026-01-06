class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // count all negative numbers
        int n = matrix.size();
        int cnt = 0;
        int mini = INT_MAX;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] <= 0) {
                    int num = matrix[i][j];
                    cnt++;
                    sum += matrix[i][j];
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans += matrix[i][j];
                mini = min(mini, abs(matrix[i][j]));
            }
        }

        // if they are even, they can be converted
        if (cnt % 2 == 0) {
            ans += 2 * abs(sum);
        }

        // if they are odd, one will be left, so keep the track of smallest
        // negative number
        if (cnt % 2 != 0) {
            ans += 2 * abs(sum);
            ans -= 2 * mini;
        }
        return ans;
    }
};