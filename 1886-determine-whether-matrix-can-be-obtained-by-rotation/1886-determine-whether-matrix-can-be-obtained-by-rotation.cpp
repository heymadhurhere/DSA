class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // water image
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[j][i], matrix[n - j - 1][i]);
            }
        }
        // diagonal rotate
        for (int col = 0; col < n; col++) {
            for (int row = 0; row < col; row++) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        //  1.
        if (mat == target)
            return true;
        // 2.
        rotate(mat);
        if (mat == target)
            return true;
        // 3.
        rotate(mat);
        if (mat == target)
            return true;
        // 4.
        rotate(mat);
        if (mat == target)
            return true;

        return false;
    }
};