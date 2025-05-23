class Solution {
public:
    int solve(int idx, int target, int sum, int offset, vector<int>& nums,
              vector<vector<int>>& dp) {
        if (idx == 0) {
            if (nums[0] == 0 && sum == target) {
                return 2;
            }
            if (nums[0] + sum == target || sum - nums[0] == target) {
                return 1;
            }
            return 0;
        }
        if (dp[idx][sum + offset] != -1) {
            return dp[idx][sum + offset];
        }
        int add = solve(idx - 1, target, sum + nums[idx], offset, nums, dp);
        int subtract =
            solve(idx - 1, target, sum - nums[idx], offset, nums, dp);
        return dp[idx][sum + offset] = add + subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int offset = totalSum;
        vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1, -1));
        return solve(n - 1, target, 0, offset, nums, dp);
    }
};