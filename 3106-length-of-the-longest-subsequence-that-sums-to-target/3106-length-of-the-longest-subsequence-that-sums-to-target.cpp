class Solution {
public:
    int solve(vector<int>& nums, vector<vector<int>>& dp, int idx, int target,
              int sum) {
        if (sum > target) {
            return INT_MIN;
        }
        if (idx == nums.size()) {
            return sum == target ? 0 : INT_MIN;
        }
        if (dp[idx][sum] != -1) {
            return dp[idx][sum];
        }
        int pick = 1 + solve(nums, dp, idx + 1, target, sum + nums[idx]);

        int notPick = solve(nums, dp, idx + 1, target, sum);
        return dp[idx][sum] = max(pick, notPick);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        int ans = solve(nums, dp, 0, target, 0);
        return ans < 0 ? -1 : ans;
    }
};