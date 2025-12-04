class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // check for smallest word in the strs
        int len = strs.size();
        if (len == 1)
            return strs[0];

        int min_word_size = strs[0].length();
        string word = strs[0];

        // take smallest word and it's size as refrence
        for (int i = 1; i < len; i++) {
            if (strs[i].length() < min_word_size) {
                word = strs[i];
                min_word_size = strs[i].length();
            }
        }

        string ans = "";
        bool flag = false;

        // traverse the matrix;
        for (int col = 0; col < min_word_size; col++) {
            char ch = strs[0][col];
            for (int row = 1; row < len; row++) {
                if (strs[row][col] != ch) {
                    return ans;
                }
            }
            ans += ch;
        }
        return ans;
    }
};