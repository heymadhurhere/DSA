class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0, j = n - 1;
        string ans = "";

        while (j >= 0) {
            // remove trailing space
            while (j >= 0 && s[j] == ' ') {
                j--;
            }

            if (j < 0) break;

            int i = j;

            // remove multiple space or leadig spaces
            while (i >= 0 && s[i] != ' ') {
                i--;
            }

            // space after each word
            if (!ans.empty()) ans += ' ';

            // i is at space or (-1)
            ans += s.substr(i + 1, j - i);

            // move j to last letter of previous word
            j = i - 1;
        }
        
        return ans;
    }
};