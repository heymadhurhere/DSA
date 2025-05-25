class Solution {
public:
    int solve(int s_idx, int t_idx, string& s, string& t,
              vector<vector<int>>& dp) {
        if (t_idx < 0) {
            return 1;
        }
        if (s_idx < 0) {
            return 0;
        }
        if (dp[s_idx][t_idx] != -1) {
            return dp[s_idx][t_idx];
        }
        int ans = 0;
        if (s[s_idx] == t[t_idx]) {
            ans = solve(s_idx - 1, t_idx - 1, s, t, dp) +
                  solve(s_idx - 1, t_idx, s, t, dp);
        } else {
            ans = solve(s_idx - 1, t_idx, s, t, dp);
        }
        return dp[s_idx][t_idx] = ans;
    }
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, s, t, dp);
    }
};