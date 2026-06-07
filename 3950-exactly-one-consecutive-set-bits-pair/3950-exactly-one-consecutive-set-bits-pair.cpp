class Solution {
public:
    string to_bin(int n) {
        string ans = "";

        while (n > 0) {
            int rem = n % 2;
            n /= 2;
            ans += rem + '0';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool consecutiveSetBits(int n) {
        string ans = to_bin(n);

        int len = ans.length();
        int cnt = 0;

        for (int i = 0; i < len - 1; i++) {
            if (ans[i] == '1' && ans[i + 1] == '1') {
                cnt++;
            }
        }
        if (cnt == 1) {
            cout << true;
            return true;
        }
        cout << false;
        return false;
    }
};