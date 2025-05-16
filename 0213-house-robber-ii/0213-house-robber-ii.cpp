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
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> nums1;
        vector<int> nums2;
        for (int i = 0; i < nums.size() - 1; i++) {
            nums1.push_back(nums[i]);
        }
        for (int i = 1; i < nums.size(); i++) {
            nums2.push_back(nums[i]);
        }
        vector<int> dp1(nums.size() - 1, -1);
        vector<int> dp2(nums.size() - 1, -1);
        return max(solve(nums1, dp1, nums.size() - 2),
                   solve(nums2, dp2, nums.size() - 2));
    }
};