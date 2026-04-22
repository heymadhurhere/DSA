class Solution {
public:
    bool check(vector<int>& freq1, vector<int>& freq2) {
        for (int i = 0; i < 128; i++) {
            if (freq1[i] > freq2[i]) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        if (n2 > n1) return "";
        vector<int> freq(128, 0);

        for (int i = 0; i < n2; i++) {
            freq[t[i]]++;
        }

        int l = 0, r = 0;
        string ans = "";
        int len = INT_MAX;
        vector<int> freq2(128, 0);
        int start = -1;

        while (r < n1) {
            freq2[s[r]]++;
            if (check(freq, freq2)) {
                while (check(freq, freq2)) {
                    if (r - l + 1 < len) {
                        start = l;
                        len = r - l + 1;
                    }
                    freq2[s[l]]--;
                    l++;
                }
            }
            r++;
        }
        if (start == -1) {
            return "";
        }
        return s.substr(start, len);
    }
};