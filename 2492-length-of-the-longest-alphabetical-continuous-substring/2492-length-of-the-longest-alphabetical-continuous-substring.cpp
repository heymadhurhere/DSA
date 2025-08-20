class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 0;
        int i = 0, j = 0, n = s.length();
        if (n == 1)
            return 1;
        while (j < n) {
            if (j + 1 < n && s[j + 1] == s[j] + 1) {
                j++;
            } else if (j + 1 < n && s[j + 1] != s[j] + 1) {
                int len = j - i + 1;
                ans = max(ans, len);
                j++;
                i = j;
            } else {
                int len = j - i + 1;
                ans = max(ans, len);
                j++;
            }
        }
        return ans;
    }
};