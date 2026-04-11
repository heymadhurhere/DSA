class Solution {
public:
    int countSubstrings(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        int ans = 0;

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (s[i] != t[j]) {
                    int leftCnt = 0;
                    while (i - leftCnt > 0 and j - leftCnt > 0 and
                           s[i - leftCnt - 1] == t[j - leftCnt - 1]) {
                        leftCnt++;
                    }

                    int rightCnt = 0;
                    while (i + rightCnt + 1 < n1 and j + rightCnt + 1 < n2 and
                           s[i + rightCnt + 1] == t[j + rightCnt + 1]) {
                        rightCnt++;
                    }
                    ans += (leftCnt + 1) * (rightCnt + 1);
                }
            }
        }
        return ans;
    }
};