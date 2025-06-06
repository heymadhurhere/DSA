class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<char> arr(n);
        arr[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            arr[i] = min(s[i], arr[i + 1]);
        }
        string t = "";
        string p = "";
        for (int i = 0; i < n; i++) {
            t.push_back(s[i]);
            while (!t.empty() && t.back() <= arr[i + 1 == n ? i : i + 1]) {
                p.push_back(t.back());
                t.pop_back();
            }
        }
        while (!t.empty()) {
            p.push_back(t.back());
            t.pop_back();
        }
        return p;
    }
};