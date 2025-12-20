class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int word = strs[0].length();
        int cnt = 0;

        for (int col = 0; col < word; col++) {
            for (int row = 1; row < n; row++) {
                if (strs[row][col] < strs[row - 1][col]) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};