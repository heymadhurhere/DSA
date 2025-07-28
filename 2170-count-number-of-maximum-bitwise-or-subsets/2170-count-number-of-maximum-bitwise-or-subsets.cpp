class Solution {
public:
    int maxOR(vector<int>& nums, int idx) {
        if (idx >= nums.size())
            return 0;
        int pick = nums[idx] | maxOR(nums, idx + 1);
        int notPick = 0 | maxOR(nums, idx + 1);
        return max(pick, notPick);
    }
    int solve(vector<int>& nums, int idx, int cnt, int maxi, int ori) {
        if (idx == nums.size()) {
            return ori == maxi ? 1 : 0;
        }
        int pick = solve(nums, idx + 1, cnt, maxi, ori | nums[idx]);
        int notPick = solve(nums, idx + 1, cnt, maxi, ori);
        return pick + notPick;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = maxOR(nums, 0);
        int ans = solve(nums, 0, 0, maxi, 0);
        return ans;
    }
};