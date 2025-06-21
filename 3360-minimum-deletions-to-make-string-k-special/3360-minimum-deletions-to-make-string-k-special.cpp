class Solution {
public:
    int solve(int i, int j, vector<int>& freq, vector<vector<int>>& dp, int k) {
        if (i == j) {
            return 0;
        }
        if (freq[j] - freq[i] <= k)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] =
                   min(freq[i] + solve(i + 1, j, freq, dp, k),
                       freq[j] - freq[i] - k + solve(i, j - 1, freq, dp, k));
    }
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        int n = word.length();
        for (int i = 0; i < n; i++) {
            freq[word[i] - 'a']++;
        }
        vector<vector<int>> dp(26, vector<int>(26, -1));
        sort(freq.begin(), freq.end());
        return solve(0, 25, freq, dp, k);
    }
};