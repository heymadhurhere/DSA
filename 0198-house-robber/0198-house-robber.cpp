class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int idx) {
        if (idx == 0)
            return nums[0];
        if (idx < 0)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int pick = nums[idx] + solve(nums, dp, idx - 2);
        int notPick = 0 + solve(nums, dp, idx - 1);
        return dp[idx] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        return solve(nums, dp, n - 1);
    }
};