class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
    }

    static bool tmp(pair<char, int>& a, pair<char, int>& b) {
        return a.second > b.second;
    }
    string sortVowels(string s) {
        int n = s.length();
        unordered_map<char, int> mpp;
        unordered_map<char, int> firstPos;

        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                mpp[s[i]]++;

                if (!firstPos.count(s[i])) {
                    firstPos[s[i]] = i;
                }
            }
        }

        vector<pair<char, int>> tmp;

        for (auto& it : mpp) {
            tmp.push_back({it.first, it.second});
        }

        sort(tmp.begin(), tmp.end(),
             [&](pair<char, int>& a, pair<char, int>& b) {
                 if (a.second != b.second) {
                     return a.second > b.second;
                 }

                 return firstPos[a.first] < firstPos[b.first];
             });

        string vowels = "";

        for (auto& it : tmp) {
            vowels += string(it.second, it.first);
        }

        int j = 0;

        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[j++];
            }
        }

        return s;
    }
};