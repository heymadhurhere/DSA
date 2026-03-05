class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n = word.length();
        if (n == 1)
            return 0;
        int cnt = 0;
        int i = 1;
        while (i < n) {
            if (abs(word[i] - word[i - 1]) <= 1) {
                cnt++;
                i += 2;
            } else
                i++;
        }
        return cnt;
    }
};