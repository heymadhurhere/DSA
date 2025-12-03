class Solution {
public:
    pair<int, int> expand(int i, int j, string s) {
        int n = s.length();
        pair<int, int> ans = {i, j};
        while (i >= 0 && j < n) {

            if (s[i] == s[j]) {
                ans = {i, j};
                i--;
                j++;
            } else {
                break;
            }
        }
        return ans;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 1)
            return s;

        int max_len = INT_MIN;
        string ans = s.substr(0, 1);
        // single letter expand
        for (int i = 0; i < n; i++) {
            pair<int, int> idxs = expand(i, i, s);
            int str_length = idxs.second - idxs.first + 1;
            if (str_length > max_len) {
                max_len = str_length;
                ans = s.substr(idxs.first, idxs.second - idxs.first + 1);
            }
        }

        // double letter expand;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                pair<int, int> idxs = expand(i, i + 1, s);
                int str_length = idxs.second - idxs.first + 1;
                if (str_length > max_len) {
                    max_len = str_length;
                    ans = s.substr(idxs.first, idxs.second - idxs.first + 1);
                }
            }
        }
        return ans;
    }
};