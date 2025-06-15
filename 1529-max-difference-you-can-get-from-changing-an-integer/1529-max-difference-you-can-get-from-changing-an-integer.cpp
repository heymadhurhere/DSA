class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string str = to_string(num);
        int n = s.length();
        // largest number
        int maxi = 0;
        char lar = '-1';
        for (int i = 0; i < n; i++) {
            if (s[i] != '9') {
                lar = s[i];
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == lar) {
                s[i] = '9';
            }
        }
        maxi = stoi(s);
        // smallest number
        int mini = 0;
        int small = '-1';
        // if str[0] == 1
        if (str[0] == '1') {
            for (int i = 1; i < n; i++) {
                if (str[i] != '1' && str[i] != '0') {
                    small = str[i];
                    break;
                }
            }
            for (int i = 0; i < n; i++) {
                if (str[i] == small) {
                    str[i] = '0';
                }
            }
            mini = stoi(str);
            return (maxi - mini);
        }
        for (int i = 0; i < n; i++) {
            if (str[i] != '1') {
                small = str[i];
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (str[i] == small) {
                str[i] = '1';
            }
        }
        mini = stoi(str);
        return (maxi - mini);
    }
};