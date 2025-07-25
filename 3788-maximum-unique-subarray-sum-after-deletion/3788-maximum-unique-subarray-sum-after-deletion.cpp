class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;
        vector<bool> vis(101, false);
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            if (nums[i] > 0 && !vis[nums[i]]) {
                sum += nums[i];
                vis[nums[i]] = true;
            }
        }
        return (sum == 0 ? maxi : sum);
    }
};