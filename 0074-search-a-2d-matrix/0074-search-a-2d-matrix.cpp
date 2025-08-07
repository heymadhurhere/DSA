class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 1 && n == 1) {
            if (matrix[0][0] == target)
                return true;
            return false;
        }
        int lr = 0, lc = 0, rr = m - 1, rc = n - 1;
        int l = matrix[lr][lc], r = matrix[rr][rc];
        while (lr <= rr) {
            int midr = lr + (rr - lr) / 2;
            if (matrix[midr][0] <= target && matrix[midr][n - 1] >= target) {
                while (lc <= rc) {
                    int midc = lc + (rc - lc) / 2;
                    if (matrix[midr][midc] == target)
                        return true;
                    else if (matrix[midr][midc] < target) {
                        lc = midc + 1;
                    } else {
                        rc = midc - 1;
                    }
                }
                return false;
            }
            else if (matrix[midr][0] > target) {
                rr = midr - 1;
            }
            else {
                lr = midr + 1;
            }
        }
        return false;
    }
};