class Solution {
public:
    int solve(string s, int k, int i, int j) {
        if (j - i < k)
            return 0;
        vector<int> freq(26, 0);
        for (int st = i; st < j; st++) {
            freq[s[st] - 'a']++;
        }
        for (int st = i; st < j; st++) {
            if (freq[s[st] - 'a'] < k) {
                int left = solve(s, k, i, st);
                int right = solve(s, k, st + 1, j);
                return max(left, right);
            }
        }
        return j - i;
    }
    int longestSubstring(string s, int k) {
        int n = s.length();
        return solve(s, k, 0, n);
    }
};