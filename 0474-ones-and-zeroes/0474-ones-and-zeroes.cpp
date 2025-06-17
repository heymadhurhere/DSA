class Solution {
public:
    vector<pair<int, int>> cnt(vector<string>& strs) {
        vector<pair<int, int>> ans;
        for (auto it : strs) {
            int zero = 0, one = 0;
            for (auto jt : it) {
                if (jt == '1')
                    one++;
                if (jt == '0')
                    zero++;
            }
            ans.push_back({zero, one});
        }
        return ans;
    }
    int solve(vector<pair<int, int>>& temp, int idx, int m, int n,
              vector<vector<vector<int>>>& dp) {
        if (idx >= temp.size()) {
            return 0;
        }
        if (dp[idx][m][n] != -1) {
            return dp[idx][m][n];
        }
        int pick = INT_MIN, notPick = INT_MIN, noOption = INT_MIN;
        if (m >= temp[idx].first && n >= temp[idx].second) {
            pick = 1 + solve(temp, idx + 1, m - temp[idx].first,
                             n - temp[idx].second, dp);
            notPick = solve(temp, idx + 1, m, n, dp);
        } else {
            noOption = solve(temp, idx + 1, m, n, dp);
        }
        return dp[idx][m][n] = max({pick, notPick, noOption});
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int p = strs.size();
        vector<pair<int, int>> temp = cnt(strs);
        vector<vector<vector<int>>> dp(
            p + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(temp, 0, m, n, dp);
    }
};