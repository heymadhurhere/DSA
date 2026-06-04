class Solution {
public:
    long long minimumCost(string s) {
        int n = s.length();
        // 2 case
        // case1 -> n is even or odd, it is same
        int mid = (n - 1) / 2;
        // case 1.1 -> make all 0
        int ops = 0;
        long long cnt1_1 = 0;
        // left part
        for (int i = mid; i >= 0; i--) {
            if (s[i] == '1') {
                if (ops % 2 == 0) {
                    cnt1_1 += (i + 1);
                    ops++;
                } else if (ops % 2 == 1)
                    continue;
            } else if (s[i] == '0') {
                if (ops % 2 == 0) {
                    continue;
                } else if (ops % 2 == 1) {
                    cnt1_1 += (i + 1);
                    ops++;
                }
            }
        }
        // right part
        ops = 0;
        for (int i = mid + 1; i < n; i++) {
            if (s[i] == '1') {
                if (ops % 2 == 0) {
                    cnt1_1 += (n - i);
                    ops++;
                } else if (ops % 2 == 1)
                    continue;
            } else if (s[i] == '0') {
                if (ops % 2 == 0) {
                    continue;
                } else if (ops % 2 == 1)
                    cnt1_1 += (n - i);
                ops++;
            }
        }

        // case 1.2 -> make all 1;
        ops = 0;
        long long cnt1_2 = 0;
        // left part
        for (int i = mid; i >= 0; i--) {
            if (s[i] == '0') {
                if (ops % 2 == 0) {
                    cnt1_2 += (i + 1);
                    ops++;
                } else if (ops % 2 == 1)
                    continue;
            } else if (s[i] == '1') {
                if (ops % 2 == 0)
                    continue;
                else if (ops % 2 == 1) {
                    cnt1_2 += (i + 1);
                    ops++;
                }
            }
        }
        // right part
        ops = 0;
        for (int i = mid + 1; i < n; i++) {
            if (s[i] == '0') {
                if (ops % 2 == 0) {
                    cnt1_2 += (n - i);
                    ops++;
                } else if (ops % 2 == 1) {
                    continue;
                }
            } else if (s[i] == '1') {
                if (ops % 2 == 0)
                    continue;
                else if (ops % 2 == 1) {
                    cnt1_2 += (n - i);
                    ops++;
                }
            }
        }
        long long ans = min(cnt1_1, cnt1_2);
        cout << ans;
        return ans;
    }
};