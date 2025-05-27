class Solution {
public:
    bool compare(string s1, string s2) {
        if (s1.length() - s2.length() != 1) {
            return false;
        }
        int cnt = 0;
        int i = 0, j = 0;
        while (i < s1.length()) {
            if (s1[i] != s2[j]) {
                cnt++;
                i++;
            } else {
                i++;
                j++;
            }
        }
        return cnt == 1;
    }
    int solve(int idx, int last, vector<string>& words,
              vector<vector<int>>& dp) {
        if (idx == words.size()) {
            return 0;
        }
        if (dp[idx][last + 1] != -1) {
            return dp[idx][last + 1];
        }
        int pick = INT_MIN, notPick = INT_MIN;
        notPick = solve(idx + 1, last, words, dp);
        if (last == -1 || compare(words[idx], words[last])) {
            pick = 1 + solve(idx + 1, idx, words, dp);
        }
        return dp[idx][last + 1] = max(pick, notPick);
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.size() < b.size(); });
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, words, dp);
    }
};