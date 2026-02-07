class Solution {
public:
    bool checkString(string s) {
        bool ans = true;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b')
                ans = false;
            if (!ans && s[i] == 'a')
                return false;
        }
        return true;
    }
};