class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        string tmp = s;
        sort(tmp.begin(), tmp.end());
        // 3 cases
        if (n == 2 && tmp != s)
            return -1;
        // case1 : ans = 0
        if (tmp == s)
            return 0;
        // case2 : ans = 1
        if (tmp[0] == s[0] || tmp[n - 1] == s[n - 1])
            return 1;
        // case3 : ans = 3
        if (s[0] == tmp[n - 1] && s[n - 1] == tmp[0]) {
            // n == 3 handling
            if (tmp[0] != tmp[1] && tmp[n - 1] != tmp[n - 2])
                return 3;
        }
        // case4 : ans = 2
        return 2;
    }
};