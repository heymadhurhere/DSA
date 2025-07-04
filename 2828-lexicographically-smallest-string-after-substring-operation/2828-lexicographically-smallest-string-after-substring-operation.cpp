class Solution {
public:
    string smallestString(string s) {
        int n = s.length();
        if (n == 1) {
            if (s == "a") {
                return "z";
            }
            char ch = ((s[0] - 'a') - 1) + 'a';
            string ans = "";
            ans += ch;
            return ans;
        }
        if (s[0] != 'a') {
            int i = 0;
            while (i < n) {
                if (s[i] == 'a') {
                    break;
                }
                i++;
            }
            for (int j = 0; j < i; j++) {
                s[j]--;
            }
            return s;
        }
        if (s[0] == 'a') {
            int i = 0;
            bool found = false;
            while (i < n) {
                if (s[i] != 'a') {
                    found = true;
                    break;
                }
                i++;
            }
            if (!found) {
                s[n - 1] = 'z';
                return s;
            }
            int j = i;
            while (j < n) {
                if (s[j] == 'a') {
                    break;
                }
                j++;
            }
            for (int k = i; k < j; k++) {
                s[k]--;
            }
            return s;
        }
        return "dummy";
    }
};