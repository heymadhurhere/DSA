class Solution {
public:
    void rotateLeft(string& s) {
        char ch = s[0];
        int n = s.length();
        for (int i = 0; i < n - 1; i++) {
            s[i] = s[i + 1];
        }
        s[n - 1] = ch;
    }
    int minOperations(string s) {
        int n = s.length();
        int ans = INT_MAX;
        int rot = 0;
        while (rot < n) {
            int tmp = rot;
            for (int i = 0; i < n / 2; i++) {
                tmp += min(abs(s[i] - s[n - i - 1]),
                           26 - abs(s[i] - s[n - i - 1]));
            }
            ans = min(ans, tmp);
            rotateLeft(s);
            rot++;
        }
        return ans;
    }
};