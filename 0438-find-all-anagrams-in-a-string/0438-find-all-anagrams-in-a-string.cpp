class Solution {
public:
    bool isAnagram(string s, string p) {
        vector<int> mpp1(26, 0), mpp2(26, 0);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            char ch1 = s[i] - 'a';
            char ch2 = p[i] - 'a';

            mpp1[ch1]++;
            mpp2[ch2]++;
        }

        return (mpp1 == mpp2);
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<int> ans;
        for (int i = 0; i <= n - m; i++) {
            string tmp = s.substr(i, m);
            if (isAnagram(tmp, p)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};