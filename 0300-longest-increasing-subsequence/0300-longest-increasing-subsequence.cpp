class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int last = idx - 1; last >= -1; last--) {
                int len = 0 + dp[idx + 1][last + 1];
                if (last == -1 || nums[last] < nums[idx]) {
                    len = max(len, 1 + dp[idx + 1][idx + 1]);
                }
                dp[idx][last + 1] = len;
            }
        }
        return dp[0][0];
    }
};