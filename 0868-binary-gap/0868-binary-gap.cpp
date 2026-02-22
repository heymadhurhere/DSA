class Solution {
public:
    string toBin(int n) {
        string tmp = "";
        while (n > 0) {
            int rem = n % 2;
            tmp += rem + '0';
            n /= 2;
        }
        reverse(tmp.begin(), tmp.end());
        return tmp;
    }
    int binaryGap(int n) {
        if ((n & (n - 1)) == 0)
            return 0;
        if ((n & (n + 1)) == 0)
            return 1;
        int ans = INT_MIN;
        string bin = toBin(n);
        int idx = 0;
        for (int i = 1; i < bin.length(); i++) {
            if (bin[i] == '1') {
                int dist = i - idx;
                ans = max(ans, dist);
                idx = i;
            }
        }
        return ans;
    }
};