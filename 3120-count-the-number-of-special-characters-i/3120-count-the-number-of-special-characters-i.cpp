class Solution {
public:
    bool isUpper(char ch) {
        if (ch >= 'A' && ch <= 'Z')
            return true;
        return false;
    }

    bool isLower(char ch) {
        if (ch >= 'a' && ch <= 'z')
            return true;
        return false;
    }
    int numberOfSpecialChars(string s) {
        vector<bool> upper(26, false), lower(26, false);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (isUpper(s[i])) {
                upper[s[i] - 'A'] = true;
            } else {
                lower[s[i] - 'a'] = true;
            }
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (upper[i] & lower[i])
                cnt++;
        }
        return cnt;
    }
};