class Solution {
public:
    int val(char ch) {
        if (ch == 'I') return 1;
        else if (ch == 'V') return 5;
        else if (ch == 'X') return 10;
        else if (ch == 'L') return 50;
        else if (ch == 'C') return 100;
        else if (ch == 'D') return 500;
        return 1000;
    }
    int romanToInt(string s) {
        int n = s.length();
        int ans = 0;
        int i = 0;
        while (i < n) {
            int tmp = 0;
            bool flag = false;
            while (i + 1 < n & val(s[i]) == val(s[i + 1])) {
                tmp += val(s[i]);
                i++;
            }
            while (i + 1 < n && val(s[i]) < val(s[i + 1])) {
                tmp = val(s[i + 1]) - val(s[i]);
                i += 2;
                ans += tmp;
                flag = true;
                continue;
            }
            if (flag) continue;
            if (i + 1 < n && val(s[i]) > val(s[i + 1])) {
                tmp += val(s[i]);
                i++;
            }
            if (i + 1 == n) {
                tmp += val(s[i]);
                i++;
            }
            ans += tmp;
        }
        return ans;
    }
};