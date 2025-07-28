class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxAND = *max_element(nums.begin(), nums.end());
        int n = nums.size(), ans = 1;
        int i = 0, j = 1;
        while (j < n) {
            if (nums[j] == maxAND && nums[j] == nums[i]) {
                ans = max(ans, j - i + 1);
                j++;
            } else {
                i = j;
                j++;
            }
        }
        return ans;
    }
};