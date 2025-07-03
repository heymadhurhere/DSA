class Solution {
public:
    char kthCharacter(int k) {
        k--;
        string str = "a";
        while (k > 0) {
            int n = str.length();
            for (int i = 0; i < n; i++) {
                str += ((str[i] - 'a' + 1) % 65) + 'a';
                k--;
                if (k == 0)
                    break;
            }
        }
        char ch = str.back();
        return ch;
    }
};