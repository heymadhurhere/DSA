class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n, vector<int>(5, 0));
        for (int i = 0; i < 5; i++) {
            dp[0][i] = 1;
        }
        if (n == 1) {
            return 5;
        }
        int cumSum = 5;
        for (int i = 1; i < n; i++) {
            dp[i][0] = cumSum;
            for (int j = 1; j < 5; j++) {
                dp[i][j] = dp[i][j - 1] - dp[i - 1][j - 1];
                cumSum += dp[i][j];
            }
        }
        return cumSum;
    }
};