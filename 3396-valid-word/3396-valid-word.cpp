class Solution {
public:
    bool isConso(char ch) {
        ch = tolower(ch);
        return isalpha(ch) &&
               !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    bool isValid(string word) {
        int n = word.length();
        if (n < 3)
            return false;
        bool vwl = false, conso = false;
        for (auto& it : word) {
            if (!isalnum(it)) {
                return false;
            }
            if (isVowel(it)) {
                vwl = true;
            }
            if (isConso(it)) {
                conso = true;
            }
        }
        return vwl && conso;
    }
};