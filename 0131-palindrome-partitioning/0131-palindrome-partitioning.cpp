class Solution {
public:
    void solve(int idx, string s, vector<string>& tmp,
               vector<vector<string>>& ans) {
        if (idx == s.length()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = idx; i < s.length(); i++) {
            if (isPalindrome(s, idx, i)) {
                tmp.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, tmp, ans);
                tmp.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int st, int e) {
        while (st <= e) {
            if (s[st++] != s[e--])
                return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        vector<vector<string>> ans;
        solve(0, s, tmp, ans);
        return ans;
    }
};