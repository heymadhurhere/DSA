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
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(s, s2, n - 1, n - 1, dp);
    }
};