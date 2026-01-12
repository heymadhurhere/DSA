class Solution {
public:
    int residuePrefixes(string s) {
        unordered_map<char, int> mpp;
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            mpp[s[i]]++;
            if (mpp.size() == (i + 1) % 3) cnt++;
        }
        return cnt;
    }
};