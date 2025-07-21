class Solution {
public:
    int maxPower(string s) {
        int ans = 1, n = s.length();
        int ch = s[0];
        if (n == 1)
            return 1;
        int i = 1, cnt = 1;
        while (i < n) {
            if (s[i] == ch) {
                cnt++;
                ans = max(ans, cnt);
            } else {
                cnt = 1;
                ch = s[i];
            }
            i++;
        }
        return ans;
    }
};