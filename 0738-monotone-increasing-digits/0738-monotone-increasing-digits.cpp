class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if (n < 10) return n;
        string s = to_string(n);
        int len = s.length();
        int idx = len;
        for (int i = len - 1; i > 0; i--) {
            if (s[i - 1] > s[i]) {
                s[i - 1]--;
                idx = i;
            }
        }
        for (int i = idx; i < len; i++) {
            s[i] = '9';
        }
        int ans = stoi(s);
        return ans;
    }
};