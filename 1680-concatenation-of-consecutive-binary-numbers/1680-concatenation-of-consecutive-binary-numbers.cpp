class Solution {
public:
    const int MOD = 1e9 + 7;
    string toBin(int n) {
        string ans = "";
        while (n > 0) {
            int rem = n % 2;
            ans += (rem + '0');
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int concatenatedBinary(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            string tmp = toBin(i);
            for (int j = 0; j < tmp.length(); j++) {
                ans = (ans * 2 + (tmp[j] - '0')) % MOD;
            }
        }
        return ans;
    }
};