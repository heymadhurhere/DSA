class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> tmp(26, 0);
        int n = sentence.length();
        for (int i = 0; i < n; i++) {
            tmp[sentence[i] - 'a']++;
        }
        for (auto& it : tmp) {
            if (it == 0) return false;
        }
        return true;
    }
};