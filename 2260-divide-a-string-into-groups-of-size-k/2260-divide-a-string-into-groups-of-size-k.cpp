class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        int rem = n % k;
        if (rem != 0) {
            for (int i = 0; i < k - rem; i++) {
                s += fill;
            }
        }
        vector<string> ans;
        for (int i = 0; i < s.length(); i += k) {
            ans.push_back(s.substr(i, k));
        }
        return ans;
    }
};