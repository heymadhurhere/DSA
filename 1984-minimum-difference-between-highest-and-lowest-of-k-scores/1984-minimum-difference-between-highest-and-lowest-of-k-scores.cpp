class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        int ans = INT_MAX;
        int n = nums.size();
        for (int i = 0; i + k - 1 < n; i++) {
            int diff = nums[i] - nums[i + k - 1];
            ans = min(ans, diff);
        }
        return ans;
    }
};