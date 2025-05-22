class Solution {
public:
    bool solve(int target, int idx, vector<int>& arr, vector<vector<int>>& dp) {
        if (target == 0) {
            return true;
        }
        if (idx == 0) {
            return (target == arr[0]);
        }
        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }
        bool pick = false;
        if (target >= arr[idx]) {
            pick = solve(target - arr[idx], idx - 1, arr, dp);
        }
        bool notPick = solve(target, idx - 1, arr, dp);
        return dp[idx][target] = pick || notPick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(target, n - 1, nums, dp);
    }
};