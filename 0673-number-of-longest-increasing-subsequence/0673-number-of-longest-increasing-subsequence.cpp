class Solution {
public:
    int findMax(vector<int> arr) {
        int n = arr.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, arr[i]);
        }
        return ans;
    }
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n);
        vector<int> count(n);
        for (int i = 0; i < n; i++) {
            LIS[i] = 1;
            count[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && LIS[j] + 1 > LIS[i]) {
                    LIS[i] = LIS[j] + 1;
                    count[i] = count[j];
                } else if (nums[i] > nums[j] && LIS[j] + 1 == LIS[i]) {
                    count[i] += count[j];
                }
            }
        }
        int maxLen = findMax(LIS);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (LIS[i] == maxLen) {
                ans += count[i];
            }
        }
        return ans;
    }
};