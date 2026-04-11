class Solution {
public:
    bool isPalindrome(string tmp) {
        int i = 0, j = tmp.length() - 1;
        while (i < j) {
            if (tmp[i] == tmp[j]) {
                i++;
                j--;
            } else
                return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            string tmp = "";
            for (int j = i; j < n; j++) {
                tmp += s[j];
                if (isPalindrome(tmp)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};