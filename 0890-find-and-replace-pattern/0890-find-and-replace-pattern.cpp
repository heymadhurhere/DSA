class Solution {
public:
    bool isomorphic(string a, string b) {
        unordered_map<char, char> mpp1;
        unordered_map<char, char> mpp2;

        int n = a.length();

        for (int i = 0; i < n; i++) {
            char c1 = a[i];
            char c2 = b[i];

            if (mpp1.count(c1) && mpp1[c1] != c2)
                return false;
            if (mpp2.count(c2) && mpp2[c2] != c1)
                return false;

            mpp1[c1] = c2;
            mpp2[c2] = c1;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words,
                                         string pattern) {
        vector<string> ans;

        for (auto& it : words) {
            if (isomorphic(it, pattern))
                ans.push_back(it);
        }

        return ans;
    }
};