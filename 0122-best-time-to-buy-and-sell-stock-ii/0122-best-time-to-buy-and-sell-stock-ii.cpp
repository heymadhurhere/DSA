class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int i = 0;
        while (i < prices.size() - 1) {
            if (prices[i + 1] > prices[i]) {
                ans += prices[i + 1] - prices[i];
            }
            i++;
        }
        return ans;
    }
};