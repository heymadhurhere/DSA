class Solution {
public:
        bool isVowel(char ch) {
            return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
        }
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;
        int cnt = 0;
        while (s[i] != ' ' && i < n) {
            if (isVowel(s[i])) {
                cnt++;
            }
            i++;
        }
        string ans = "";
        i = 0;
        while (s[i] != ' ' && i < n) {
            ans += s[i];
            i++;
        }
        int j = i + 1;
        i = j;
        while (i < n) {
            int c = 0;
            while (s[j] != ' ' && j < n) {
                if (isVowel(s[j])) c++;
                j++;
            }
            string tmp = s.substr(i, j - i);
            if (c == cnt) {
                reverse(tmp.begin(), tmp.end());
            }
            ans += ' ';
            ans += tmp;

            i = j + 1;
            j = i;
        }
        return ans;
    }
};