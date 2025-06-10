class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }
        sort(freq.begin(), freq.end());
        int even = 0, odd = 0;
        for (int i = 25; i >= 0; i--) {
            if (freq[i] % 2 != 0) {
                odd = freq[i];
                break;
            }
        }
        for (int i = 1; i < 26; i++) {
            if (freq[i] % 2 == 0 && freq[i] != 0) {
                even = freq[i];
                break;
            }
        }
        return odd - even;
    }
};