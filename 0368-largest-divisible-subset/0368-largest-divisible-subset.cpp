class Solution {
public:
    int solve(int idx, int last, vector<int>& nums, vector<vector<int>>& dp,
              vector<vector<int>>& path) {
        if (idx == nums.size()) {
            return 0;
        }
        if (dp[idx][last + 1] != -1) {
            return dp[idx][last + 1];
        }
        int notTake = solve(idx + 1, last, nums, dp, path);
        int take = INT_MIN;
        if (last == -1 || nums[idx] % nums[last] == 0) {
            take = 1 + solve(idx + 1, idx, nums, dp, path);
        }
        if (take > notTake) {
            path[idx][last + 1] = 1;
        } else {
            path[idx][last + 1] = 0;
        }
        return dp[idx][last + 1] = max(take, notTake);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        vector<vector<int>> path(n, vector<int>(n + 1, -1));
        int dummy = solve(0, -1, nums, dp, path);
        int idx = 0, last = -1;
        vector<int> ans;
        while (idx < n) {
            if (path[idx][last + 1] == 1) {
                ans.push_back(nums[idx]);
                last = idx;
            }
            idx++;
        }
        return ans;
    }
};