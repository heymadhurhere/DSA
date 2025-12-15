class Solution {
public:
    long long calc(long long n) { return (n * (n + 1)) / 2; }
    long long getDescentPeriods(vector<int>& prices) {
        long long n = prices.size();
        if (n == 1)
            return 1;
        int i = 0, j = 1;
        int len = 0;
        long long ans = 0;
        while (j < n) {
            if (prices[j - 1] - prices[j] == 1) {
                j++;
            } else {
                len = j - i;
                ans += calc(len);
                i = j;
                j = j + 1;
            }
        }
        ans += calc(j - i);
        // ans += n;
        return ans;
    }
};