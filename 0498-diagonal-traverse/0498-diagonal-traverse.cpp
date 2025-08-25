class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            int row = i, col = 0;
            vector<int> tmp;
            while (row >= 0 && col < m) {
                tmp.push_back(mat[row][col]);
                row--;
                col++;
            }
            if (i % 2 == 1) {
                reverse(tmp.begin(), tmp.end());
            }
            ans.push_back(tmp);
        }
        for (int j = 1; j < m; j++) {
            int row = n - 1, col = j;
            vector<int> tmp;
            while (row >= 0 && col < m) {
                tmp.push_back(mat[row][col]);
                row--;
                col++;
            }
            if ((n - 1 + j) % 2 == 1) {
                reverse(tmp.begin(), tmp.end());
            }
            ans.push_back(tmp);
        }
        vector<int> res;
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                res.push_back(ans[i][j]);
            }
        }
        return res;
    }
};