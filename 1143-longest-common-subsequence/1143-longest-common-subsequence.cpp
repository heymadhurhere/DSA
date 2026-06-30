class Solution {
public:
    int solve(string& text1, string& text2, int idx1, int idx2,
              vector<vector<int>>& dp) {
        if (idx1 < 0 || idx2 < 0) {
            return 0;
        }
        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }
        int len = 0;
        if (text1[idx1] == text2[idx2]) {
            len = 1 + solve(text1, text2, idx1 - 1, idx2 - 1, dp);
        }
        return dp[idx1][idx2] =
                   max({len, solve(text1, text2, idx1 - 1, idx2, dp),
                        solve(text1, text2, idx1, idx2 - 1, dp)});
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(text1, text2, m - 1, n - 1, dp);
    }
};