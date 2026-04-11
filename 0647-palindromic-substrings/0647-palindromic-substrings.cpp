class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            cnt++;
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                cnt++;
            }
        }

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (dp[i + 1][j - 1] and s[i] == s[j]) {
                    dp[i][j] = true;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};