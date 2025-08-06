class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(rowIndex + 1);
        ans[0] = {1};
        for (int i = 1; i <= rowIndex; i++) {
            vector<int> temp(i + 1);
            temp[0] = 1;
            temp[i] = 1;
            for (int j = 1; j < i; j++) {
                temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans[i] = temp;
        }
        return ans[rowIndex];
    }
};