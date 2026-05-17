class Solution {
public:
    bool solve(string& s, vector<string>& wordDict, int pt, vector<int>& dp) {
        if (pt == s.length())
            return true;

        if (dp[pt] != -1) {
            return dp[pt];
        }

        for (int i = 0; i < wordDict.size(); i++) {
            int n = wordDict[i].size();
            if (pt + n <= s.length() and s.substr(pt, n) == wordDict[i]) {
                if (solve(s, wordDict, pt + n, dp))
                    return dp[pt] = 1;
            }
        }
        return dp[pt] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int pt = 0;
        int m = s.length();
        vector<int> dp(m, -1);
        return solve(s, wordDict, pt, dp);
    }
};