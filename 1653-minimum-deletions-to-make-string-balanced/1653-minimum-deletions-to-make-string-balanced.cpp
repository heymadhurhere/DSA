class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        if (n == 1)
            return 0;
        vector<int> a(n), b(n);
        a[n - 1] = (s[n - 1] == 'a' ? 1 : 0);
        for (int i = n - 2; i >= 0; i--) {
            a[i] = a[i + 1] + (s[i] == 'a' ? 1 : 0);
        }
        b[0] = (s[0] == 'b' ? 1 : 0);
        for (int i = 1; i < n; i++) {
            b[i] = b[i - 1] + (s[i] == 'b' ? 1 : 0);
        }
        if (a[0] == n || b[n - 1] == n)
            return 0;
        int ans = min(a[0], b[n - 1]);
        for (int i = 0; i < n; i++) {
            ans = min(ans, a[i] + (i > 0 ? b[i - 1] : 0));
        }
        return ans;
    }
};