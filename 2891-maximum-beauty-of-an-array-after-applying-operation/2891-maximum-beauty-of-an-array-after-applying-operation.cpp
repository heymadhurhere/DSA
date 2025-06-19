class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        int bufferDiff = 2 * k;
        int ans = INT_MIN;
        while (j < n) {
            if (nums[j] - nums[i] <= bufferDiff) {
                ans = max(ans, j - i + 1);
                j++;
            } else {
                i++;
            }
        }
        return ans;
    }
};