class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int denom = 2; denom <= n; denom++) {
            for (int numer = 1; numer < denom; numer++) {
                if (__gcd(numer, denom) == 1) {
                    string up = to_string(numer), down = to_string(denom);
                    string res = up + "/" + down;
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
};