class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mpp1(26, 0), mpp2(26, 0);
        int n = s.length();

        if (n != t.length())
            return false;

        for (int i = 0; i < n; i++) {
            mpp1[s[i] - 'a']++;
            mpp2[t[i] - 'a']++;
        }

        return (mpp1 == mpp2);
    }
};