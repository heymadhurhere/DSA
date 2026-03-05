class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if (n == 1)
            return 0;
        int cnt1 = 0, cnt2 = 0;
        // try 10101010....
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (s[i] == '0') {
                    // s[i] = '1';
                    cnt1++;
                }
            }
            if (i % 2 == 1) {
                if (s[i] == '1') {
                    // s[i] = '0';
                    cnt1++;
                }
            }
        }

        // try 01010101...
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (s[i] == '1') {
                    // s[i] = '0';
                    cnt2++;
                }
            }
            if (i % 2 == 1) {
                if (s[i] == '0') {
                    // s[i] = '1';
                    cnt2++;
                }
            }
        }
        return min(cnt1, cnt2);
    }
};